// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RifeAnim.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeathEndDispatcher);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FActionCompleteDispatcher);

UCLASS()
class ENGINEDEVELOPMENT_API URifeAnim : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	URifeAnim();
	void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	float Speed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	float Direction;

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = Fucntion)
		FActionCompleteDispatcher OnComplete;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
		FDeathEndDispatcher OnDeathFinished;

	UFUNCTION(BlueprintCallable)
		void AnimationComplete();

	UFUNCTION(BlueprintCallable)
		void PlayShootAnimation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UAnimSequence* ShootAsset;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PersonaUpdate();
	void PersonaUpdate_Implementation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool DebugShoot;

	UPROPERTY(BlueprintReadonly, EditAnywhere, Category = "Death")
		TArray<class UAnimSequence*> DeathAnimations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
		class UAnimSequence* CurrentDeath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
		class UAnimSequence* DamagedAnimation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Death")
	int DeathIndex = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
		bool DebugDeath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
		bool DebugDamaged;

	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void PlayDeathAnimation(float Ratio);
		//void PlayDeathAnimation_Implementation(float Ratio);

	UFUNCTION(BlueprintCallable)
		void PlayDamagedAnimation(float Ratio);

	UFUNCTION(BlueprintCallable)
		void SetDeathTimerEvent();

	UFUNCTION(BlueprintCallable)
		void DeathFinished();

};
