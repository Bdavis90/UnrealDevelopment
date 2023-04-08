// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RifeAnim.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API URifeAnim : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	void NativeUpdateAnimation(float DeltaSeconds) override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	float Speed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	float Direction;
};
