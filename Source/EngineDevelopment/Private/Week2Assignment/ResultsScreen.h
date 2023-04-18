// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ResultsScreen.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API UResultsScreen : public UUserWidget
{
	GENERATED_BODY()

		void NativePreConstruct() override;

	void NativeConstruct() override;

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
		class UButtonWidget* RestartButton;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
		class UButtonWidget* MainMenuButton;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
		class UWidgetSwitcher* ResultsSwitch;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
		class UVerticalBox* ButtonBox;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UEndGameInstance* EndGameInstance;

	UFUNCTION()
		void SetWin();

	UFUNCTION()
		void SetLose();
	
};
