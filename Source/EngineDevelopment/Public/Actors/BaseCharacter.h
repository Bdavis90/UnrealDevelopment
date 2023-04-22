// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Abstract)
class ENGINEDEVELOPMENT_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = "Child Component")
	class UChildActorComponent* WeaponChild;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	class ABaseWeapon* WeaponClass;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	class ABaseWeapon* CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class URifeAnim* ABP_Rifle;

	UFUNCTION(BlueprintCallable)
	void PlayShootAnimation();

	UFUNCTION(BlueprintCallable)
	void StopAnimation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAnimSequence* ShootAsset;

	UFUNCTION(BlueprintCallable)
	void CharacterShoot();

	UFUNCTION(BlueprintCallable)
	virtual void CharacterDeath(float Ratio);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	class UHealthComponent* HealthComponent;

	UFUNCTION(BlueprintCallable)
	void CharacterDamage(float Ratio);

	UFUNCTION(BlueprintCallable)
	virtual void CharacterDeathFinished();

	UFUNCTION(BlueprintCallable)
	virtual void CharacterAmmoChanged(float Current, float Max);

	UFUNCTION()
	virtual void CharacterReload();

	UFUNCTION()
	virtual void WeaponActionEnded();


};
