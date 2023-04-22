// Fill out your copyright notice in the Description page of Project Settings.


#include "ReloadNotify.h"
#include "Core/RifeAnim.h"

void UReloadNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	URifeAnim* RifleAinmRef = Cast<URifeAnim>(MeshComp->GetAnimInstance());
	if (RifleAinmRef)
	{
		RifleAinmRef->ReloadWeapon();
	}
}
