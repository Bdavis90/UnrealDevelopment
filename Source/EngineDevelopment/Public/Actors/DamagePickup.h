
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BasePickup.h"
#include "DamagePickup.generated.h"

/**
 *
 */
UCLASS()
class ENGINEDEVELOPMENT_API ADamagePickup : public ABasePickup
{
	GENERATED_BODY()
public:
	ADamagePickup();

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Damage = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<UDamageType> DamageTypeClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UParticleSystemComponent* ParticleSystem;

public:

	virtual void HandlePickup(AActor* OtherActor, FHitResult SweepResult) override;

	virtual void HandlePostPickup() override;
};