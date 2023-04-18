// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "../Interfaces/WeaponInterface.h"
#include "BaseAI.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API ABaseAI : public ABaseCharacter, public IWeaponInterface
{
	GENERATED_BODY()
protected:

		virtual void Tick(float DeltaTime) override;

public:
	// Inherited via IWeaponInterface
	virtual void Shoot() override;

	void CharacterDeath(float _Ratio) override;

	void CharacterDeathFinished() override;

};

