// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RifeAnim.h"

URifeAnim::URifeAnim()
{
	ConstructorHelpers::FObjectFinder<UAnimSequence>Asset(TEXT("AnimSequence'/Game/END_Starter/Mannequin/A_Fire_Ironsights.A_Fire_Ironsights'"));
	ShootAsset = Asset.Object;
	DebugShoot = false;
	DebugDeath = false;
}

void URifeAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Pawn = TryGetPawnOwner();
	if (Pawn)
	{
		FVector Vel = Pawn->GetVelocity();
		FRotator Rot = Pawn->GetActorRotation();
		Speed = Vel.Size();
		Direction = CalculateDirection(Vel, Rot);
	}
	else
	{
		PersonaUpdate_Implementation();
	}
}

void URifeAnim::AnimationComplete()
{
	OnComplete.Broadcast();
}

void URifeAnim::PlayShootAnimation()
{
	PlaySlotAnimationAsDynamicMontage(ShootAsset, TEXT("Action"));
}


void URifeAnim::PersonaUpdate_Implementation()
{
	if (DebugShoot)
	{
		DebugShoot = false;
		PlayShootAnimation();
	}

	if (DebugDeath)
	{
		DebugDeath = false;
		PlayDeathAnimation(0);
	}
	else if(DebugDamaged)
	{
		DebugDamaged = false;
		PlayDamagedAnimation(0);
	}
}

void URifeAnim::PlayDeathAnimation(float Ratio)
{
	DeathIndex = FMath::RandRange(0, DeathAnimations.Num() - 1);
	CurrentDeath = DeathAnimations[DeathIndex];
}

void URifeAnim::PlayDamagedAnimation(float Ratio)
{
	PlaySlotAnimationAsDynamicMontage(DamagedAnimation, TEXT("Damage"));
}
