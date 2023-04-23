// Fill out your copyright notice in the Description page of Project Settings.


#include "ReloadNow.h"
#include "Core/RifeAnim.h"

void UReloadNow::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	URifeAnim* RifleAinmRef = Cast<URifeAnim>(MeshComp->GetAnimInstance());
	if (RifleAinmRef)
	{
		RifleAinmRef->ReloadComplete();
	}
}
