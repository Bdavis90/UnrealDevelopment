// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "BaseAI.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API ABaseAI : public ABaseCharacter
{
	GENERATED_BODY()
		virtual void Tick(float DeltaTime) override;
};
