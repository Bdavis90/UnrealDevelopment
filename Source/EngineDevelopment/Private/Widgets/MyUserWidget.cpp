// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/MyUserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"

UMyUserWidget::UMyUserWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMyUserWidget::SetHealth(float Ratio)
{
	Health->SetPercent(Ratio);
}
