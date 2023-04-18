// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "BasePlayer.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerDiedDispatcher);

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API ABasePlayer : public ABaseCharacter
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* Camera;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);

	void MoveRight(float Value);

public:
	ABasePlayer();
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
		FPlayerDiedDispatcher OnPlayerDied;

	UPROPERTY(EditAnywhere, Category = "HUD")
	TSubclassOf<class UMyUserWidget> WidgetClass;

	class UMyUserWidget* HUD;

	void CharacterDeath(float Ratio) override;

	APlayerController* PlayerController;

	UFUNCTION(BlueprintCallable, Category = "Game")
		void WonLevel();

	void CharacterDeathFinished() override;

};
