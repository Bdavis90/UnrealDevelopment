// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseWeapon.h"
#include "../../EngineDevelopment.h"
#include "Actors/BaseProjectile.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ABaseWeapon::ABaseWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	RootComponent = SkeletalMesh;

	ConstructorHelpers::FObjectFinder<USkeletalMesh>Asset(TEXT("SkeletalMesh'/Game/END_Starter/Guns/Rifle/SK_Rifle.SK_Rifle'"));
	SkeletalMesh->SetSkeletalMesh(Asset.Object);
	SetRootComponent(SkeletalMesh);

	Max = 5;
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	OwningPawn = Cast<APawn>(GetParentActor());
	if (!OwningPawn)
	{
		UE_LOG(Game, Error, TEXT("We need a pawn to own this weapon"));
		return;
	}

	Reload();
}

bool ABaseWeapon::CanShoot() const
{
	if(!Animating && !Dead && Current > 0)
		return true;
	return false;
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseWeapon::Shoot()
{
	if (CanShoot())
	{
		FActorSpawnParameters Params;
		Params.Owner = GetWorld()->GetFirstPlayerController();
		Params.Instigator = OwningPawn;

		GetWorld()->SpawnActor<AActor>(ProjectileClass, SkeletalMesh->GetSocketLocation(TEXT("MuzzleFlashSocket")), GetShotRotation(), Params);

		Animating = true;

		OnShoot.Broadcast();
		UseAmmo();
	}

}

void ABaseWeapon::StopAnimation()
{
	Animating = false;
}

FRotator ABaseWeapon::GetShotRotation()
{

	TArray<UUserWidget*> Widgets;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), Widgets, UMyUserWidget::StaticClass(), false);

	FRotator Rotation = OwningPawn->GetBaseAimRotation();

	if (Widgets.Num() > 0)
	{
		UMyUserWidget* WidgetRef = Cast<UMyUserWidget>(Widgets[0]);

		if (WidgetRef && WidgetRef->GetOwningPlayerPawn() == OwningPawn)
		{
			bool bHit;
			FVector HitLocation;
			FVector EndLocation;
			WidgetRef->GetAimedPoint(bHit, HitLocation, EndLocation);

			FVector Destination = bHit ? HitLocation : EndLocation;

			Rotation = UKismetMathLibrary::MakeRotFromX(Destination -= SkeletalMesh->GetSocketLocation(TEXT("MuzzleFlashSocket")));
		}
	}

	return Rotation;
}

void ABaseWeapon::Reload()
{
	Current = Max;
	OnAmmoChanged.Broadcast(Current, Max);
}

void ABaseWeapon::UseAmmo()
{
	Current = FMath::Clamp(Current - 1, 0.f, Max);
	OnAmmoChanged.Broadcast(Current, Max);
}

