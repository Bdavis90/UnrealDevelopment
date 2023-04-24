// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter.h"
#include "Components/ChildActorComponent.h"
#include "Actors/BaseWeapon.h"
#include "../../Public/Core/RifeAnim.h"
#include "../../EngineDevelopment.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/HealthComponent.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetWorldRotation(FRotator(0.f, -90.f, 0.f));
	GetMesh()->SetWorldLocation(FVector(0.f, 0.f, -90.f));

	WeaponChild = CreateDefaultSubobject<UChildActorComponent>(TEXT("WeaponChild"));
	WeaponChild->SetupAttachment(GetMesh(), TEXT("WeaponSocket"));

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	CurrentWeapon = Cast<ABaseWeapon>(WeaponChild->GetChildActor());
	if (!CurrentWeapon)
	{
		UE_LOG(Game, Error, TEXT("Character needs a weapon"));
		return;
	}

	ABP_Rifle = Cast<URifeAnim>(GetMesh()->GetAnimInstance());
	if (!ABP_Rifle)
	{
		UE_LOG(Game, Error, TEXT("Character needs a ABP_Rifle"));
		return;
	}
	CurrentWeapon->OnShoot.AddDynamic(this, &ABaseCharacter::PlayShootAnimation);
	CurrentWeapon->OnAmmoChanged.AddDynamic(this, &ABaseCharacter::CharacterAmmoChanged);
	CurrentWeapon->OnReloadStart.AddDynamic(ABP_Rifle, &URifeAnim::PlayReloadAnimation);
	ABP_Rifle->OnComplete.AddDynamic(this, &ABaseCharacter::WeaponActionEnded);
	ABP_Rifle->OnDeathFinished.AddDynamic(this, &ABaseCharacter::CharacterDeathFinished);
	ABP_Rifle->OnReload.AddDynamic(CurrentWeapon, &ABaseWeapon::Reload);
	HealthComponent->OnDeath.AddDynamic(this, &ABaseCharacter::CharacterDeath);
	HealthComponent->OnDamage.AddDynamic(ABP_Rifle, &URifeAnim::PlayDamagedAnimation);
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

void ABaseCharacter::CharacterDeath(float Ratio)
{
	GetCharacterMovement()->StopMovementImmediately();
	ABP_Rifle->PlayDeathAnimation(Ratio);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CurrentWeapon->Dead = true;
}

void ABaseCharacter::CharacterDamage(float Ratio)
{
	ABP_Rifle->PlayDamagedAnimation(Ratio);
}

void ABaseCharacter::CharacterDeathFinished()
{
}

void ABaseCharacter::CharacterAmmoChanged(float Current, float Max)
{
}

void ABaseCharacter::CharacterWeaponActionEnded()
{
}

void ABaseCharacter::CharacterReload()
{
	CurrentWeapon->CheckStartReload();
}

void ABaseCharacter::WeaponActionEnded()
{
	CurrentWeapon->Animating = false;
}




