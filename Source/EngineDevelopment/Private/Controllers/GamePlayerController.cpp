// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/GamePlayerController.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void AGamePlayerController::BeginPlay()
{
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(this);
}
