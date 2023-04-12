// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadonly, meta=(BindWidget))
	class UProgressBar* Health;
	UPROPERTY(BlueprintReadonly, meta = (BindWidget))
	class UImage* Reticle;
public:
	UMyUserWidget(const FObjectInitializer& ObjectInitializer);
	void NativeConstruct() override;
	UFUNCTION()
	void SetHealth(float Ratio);
};
