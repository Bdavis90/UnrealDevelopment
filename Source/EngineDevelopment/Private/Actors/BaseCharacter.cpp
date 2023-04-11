// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter.h"
#include "Components/ChildActorComponent.h"
#include "Actors/BaseWeapon.h"
#include "../../Public/Core/RifeAnim.h"
#include "../../EngineDevelopment.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetWorldRotation(FRotator(0.f, -90.f, 0.f));
	GetMesh()->SetWorldLocation(FVector(0.f, 0.f, -90.f));

	WeaponChild = CreateDefaultSubobject<UChildActorComponent>(TEXT("WeaponChild"));
	WeaponChild->SetupAttachment(GetMesh(), TEXT("WeaponSocket"));
	

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentWeapon = Cast<ABaseWeapon>(WeaponChild->GetChildActor());
	CurrentWeapon->OnShoot.AddDynamic(this, &ABaseCharacter::PlayShootAnimation);
	if (!CurrentWeapon)
	{
		UE_LOG(Game, Error, TEXT("Character needs a weapon"))
	}

	ABP_Rifle = Cast<URifeAnim>(GetMesh()->GetAnimInstance());
	if (ABP_Rifle)
	{
		auto name = GetName();
		ABP_Rifle->OnComplete.AddDynamic(this, &ABaseCharacter::StopAnimation);
	}


}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ABaseCharacter::PlayShootAnimation()
{
	ABP_Rifle->PlaySlotAnimationAsDynamicMontage(ShootAsset, TEXT("Action"));
}

void ABaseCharacter::StopAnimation()
{
	CurrentWeapon->StopAnimation();
}

void ABaseCharacter::CharacterShoot()
{
	CurrentWeapon->Shoot();
}




