// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDamageDispatcher, float, Ratio);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeathDispatcher, float, Ratio);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ENGINEDEVELOPMENT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION()
	void SetStartHealth();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Component");
	float Max;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health Component");
	float Current;
	UFUNCTION()
	void HandleDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	UPROPERTY()
	FDamageDispatcher OnDamage;
	UPROPERTY()
	FDeathDispatcher OnDeath;
};
