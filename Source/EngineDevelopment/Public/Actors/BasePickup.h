// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePickup.generated.h"

UCLASS(Abstract)
class ENGINEDEVELOPMENT_API ABasePickup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABasePickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UBoxComponent* Collision;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		virtual void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
		virtual void HandlePickup(AActor* OtherActor, FHitResult SweepResult);

	UFUNCTION(BlueprintCallable)
		virtual void HandlePostPickup();

	UFUNCTION(BlueprintCallable)
		virtual bool ShouldActivate(AActor* OtherActor) const;

	UFUNCTION(BlueprintCallable)
		virtual void HandleNoPickup();

};