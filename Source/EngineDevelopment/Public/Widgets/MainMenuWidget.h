// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
protected:

	void NativePreConstruct() override;
	void NativeConstruct() override;

public:
		UPROPERTY(BlueprintReadonly, meta = (BindWidget))
		class UImage* Background;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
		class UButtonWidget* StartButton;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
		class UButtonWidget* QuitButton;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
		class UVerticalBox* ButtonBox;

		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UEndGameInstance* EndGameInstance;
};
