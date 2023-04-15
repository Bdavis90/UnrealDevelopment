// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootState.h"
#include "Core/RifeAnim.h"

void UShootState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	URifeAnim* RifleAinmRef = Cast<URifeAnim>(MeshComp->GetAnimInstance());
	if (RifleAinmRef)
	{
		RifleAinmRef->AnimationComplete();
	}
}
