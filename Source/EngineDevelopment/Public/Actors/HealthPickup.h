// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/DamagePickup.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API AHealthPickup : public ADamagePickup
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		USoundBase* Sound;

public:
	void HandleNoPickup() override;

	void HandlePostPickup() override;

	bool ShouldActivate(AActor* Other) const override;
	
};
