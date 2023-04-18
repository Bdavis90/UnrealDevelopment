// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FButtonClicked);
/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API UButtonWidget : public UUserWidget
{
	GENERATED_BODY()

		void NativePreConstruct() override;
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
		class UButton* BackgroundButton;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
		class UTextBlock* Info;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText ButtonText;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	 FButtonClicked OnButtonClicked;

	UFUNCTION()
		void ButtonClicked();
};
