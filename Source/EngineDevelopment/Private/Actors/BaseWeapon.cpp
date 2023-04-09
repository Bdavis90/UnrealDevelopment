// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseWeapon.h"
#include "../../EngineDevelopment.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	RootComponent = SkeletalMesh;
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

	
}

bool ABaseWeapon::CanShoot()
{
	return !Animating;
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseWeapon::Shoot()
{
	FVector SocketLocation = SkeletalMesh->GetSocketLocation("MuzzleFlashSocket");
	FRotator AimRotation = OwningPawn->GetBaseAimRotation();
	AController* OwnerController = OwningPawn->GetController();
	FActorSpawnParameters Params;
	Params.Owner = OwningPawn->GetController();
	Params.Instigator = OwningPawn;
	GetWorld()->SpawnActor<AActor>(ProjectileClass, SocketLocation, AimRotation, Params);
}

