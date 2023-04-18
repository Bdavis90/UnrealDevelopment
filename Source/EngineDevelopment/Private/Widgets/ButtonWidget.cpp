// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ButtonWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UButtonWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	Info->SetText(ButtonText);
	BackgroundButton->OnClicked.AddDynamic(this, &UButtonWidget::ButtonClicked);
}

void UButtonWidget::ButtonClicked()
{
	OnButtonClicked.Broadcast();
}
