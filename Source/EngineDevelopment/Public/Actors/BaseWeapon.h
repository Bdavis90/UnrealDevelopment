// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShootDispatcher);


UCLASS()
class ENGINEDEVELOPMENT_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool Animating = false;
	UFUNCTION(BlueprintCallable, Category = "Function")
	bool CanShoot() const;
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	USkeletalMeshComponent* SkeletalMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	APawn* OwningPawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ABaseProjectile> ProjectileClass;
	UFUNCTION(BlueprintCallable, Category = "Function")
	void Shoot();
	UFUNCTION(BlueprintCallable, Category = "Function")
	void StopAnimation();
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = Fucntion)
	FShootDispatcher OnShoot;


	
	
};
