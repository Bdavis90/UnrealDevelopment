// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "ShootState.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API UShootState : public UAnimNotifyState
{
	GENERATED_BODY()
	
public:
	void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
