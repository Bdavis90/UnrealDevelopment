// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CodeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API ACodeGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameMode")
		int NumberOfEnemies = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameMode")
		class APlayerController* ActivePC;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameMode")
		class UResultsScreen* ResultsWidget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameMode")
		class UEndGameInstance* GameInstance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameMode")
		int TimeToSeeWinScreen = 3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameMode")
		class ABasePlayer* ActivePlayer;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameMode")
	TSubclassOf< class UResultsScreen> ResultsClass;

public:
	void BeginPlay() override;

	UFUNCTION()
		void EnemyDestoryed(AActor* DestroyedActor);

	UFUNCTION()
		void PlayerDestoryed();
	
};
