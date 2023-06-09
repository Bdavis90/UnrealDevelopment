// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodeInterface.h"
#include "ActorWithInterfaces.generated.h"

UCLASS()
class ENGINEDEVELOPMENT_API AActorWithInterfaces : public AActor, public ICodeInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorWithInterfaces();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Inherited via ICodeInterface
	virtual void BlueprintCallable() override;

};
