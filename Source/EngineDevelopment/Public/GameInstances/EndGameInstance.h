// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EndGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API UEndGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameInstance")
		TArray<FName> Levels;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameInstance")
		int FirstLevelIndex = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameInstance")
		int CurrentLevel = 0;

public:
	UFUNCTION(BlueprintCallable, Category = "GameInstance")
		void QuitGame();

	UFUNCTION(BlueprintCallable, Category = "GameInstance")
		void LoadMainMenu();

	UFUNCTION(BlueprintCallable, Category = "GameInstance")
		void LoadFirstLevel();

	UFUNCTION(BlueprintCallable, Category = "GameInstance")
		void ReloadLevel();

private:
	UFUNCTION()
		void LoadLevelSafe(int Index);
	
};
