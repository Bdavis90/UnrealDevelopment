// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

UCLASS()
class ENGINEDEVELOPMENT_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	class USphereComponent* Collision;
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	class UProjectileMovementComponent* Movement;
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	UStaticMeshComponent* Mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void HandleCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	float TimeToDestroy;
	UFUNCTION()
	void TimerEnded();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;
};
