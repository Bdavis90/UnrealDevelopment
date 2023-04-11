// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RifeAnim.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FActionCompleteDispatcher);

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
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = Fucntion)
		FActionCompleteDispatcher OnComplete;
	UFUNCTION()
		void AnimationComplete();
	

};
