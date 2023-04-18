// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/MenuPlayerController.h"
#include "Widgets/MainMenuWidget.h"
#include <Blueprint/WidgetBlueprintLibrary.h>

void AMenuPlayerController::BeginPlay()
{

	if (!MainMenuClass)
	{
		UE_LOG(LogTemp, Error, TEXT("MainMenuClass not set"));
		return;
	}
	bShowMouseCursor = true;
	MainMenu = CreateWidget<UMainMenuWidget>(this, MainMenuClass);
	MainMenu->AddToViewport();
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(this, MainMenu, EMouseLockMode::LockAlways);
}
