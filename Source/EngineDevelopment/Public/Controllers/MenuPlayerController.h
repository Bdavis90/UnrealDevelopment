// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API AMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

	void BeginPlay() override;
public:
	class UMainMenuWidget* MainMenu;
	UPROPERTY(EditAnywhere, Category = "MainMenu")
	TSubclassOf<class UMainMenuWidget> MainMenuClass;
	
};
