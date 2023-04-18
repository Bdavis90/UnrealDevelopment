// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstances/EndGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UEndGameInstance::QuitGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), GetFirstLocalPlayerController(), EQuitPreference::Quit, false);
}

void UEndGameInstance::LoadMainMenu()
{
	LoadLevelSafe(0);
}

void UEndGameInstance::LoadFirstLevel()
{
	LoadLevelSafe(FirstLevelIndex);
}

void UEndGameInstance::ReloadLevel()
{
	LoadLevelSafe(CurrentLevel);
}

void UEndGameInstance::LoadLevelSafe(int Index)
{
	if (Levels.IsValidIndex(Index))
	{
		CurrentLevel = Index;
		UGameplayStatics::OpenLevel(GetWorld(), Levels[CurrentLevel]);

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid Index: %f"), CurrentLevel);
	}
}
