// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RifeAnim.h"

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
