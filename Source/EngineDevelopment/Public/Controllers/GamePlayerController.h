// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;
};
