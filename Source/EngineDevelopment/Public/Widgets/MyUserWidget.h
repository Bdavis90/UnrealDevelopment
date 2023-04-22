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
	class UProgressBar* Health = nullptr;

	UPROPERTY(BlueprintReadonly, meta = (BindWidget))
	class UImage* Reticle = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		UMaterialInstanceDynamic* DynamicMaterial = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector HitLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector EndPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bValidHit = false;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* CurrentAmmo;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* MaxAmmo;

public:
	UMyUserWidget(const FObjectInitializer& ObjectInitializer);
	void NativeConstruct() override;

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetHealth(float Ratio);

	UFUNCTION(BlueprintCallable)
		void SetMatColor(FLinearColor Color);

	UFUNCTION(BlueprintCallable)
		void SetAmmo(float Current, float Max);

	UFUNCTION()
		void GetLinePoints(FVector& _StartPoint, FVector& _EndPoint) const;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FLinearColor DangerColor = FLinearColor(1, 0, 0, 1);

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FLinearColor DefaultColor = FLinearColor(0, 0.7, 0.7, 1);

	UFUNCTION(BlueprintCallable)
		void GetAimedPoint(bool& Valid, FVector& Hit, FVector& End) const;

};
