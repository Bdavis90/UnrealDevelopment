// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RifeAnim.h"

URifeAnim::URifeAnim()
{
	ConstructorHelpers::FObjectFinder<UAnimSequence>Asset(TEXT("AnimSequence'/Game/END_Starter/Mannequin/A_Fire_Ironsights.A_Fire_Ironsights'"));
	ShootAsset = Asset.Object;
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
}

void URifeAnim::AnimationComplete()
{
	OnComplete.Broadcast();
}

void URifeAnim::PlayShootAnimation()
{
	PlaySlotAnimationAsDynamicMontage(ShootAsset, TEXT("Action"));
}
