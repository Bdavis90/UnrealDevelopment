// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ResultsScreen.h"
#include "Components/VerticalBox.h"
#include "Components/WidgetSwitcher.h"
#include "GameInstances/EndGameInstance.h"
#include "Widgets/ButtonWidget.h"
#include "Components/Button.h"

void UResultsScreen::NativePreConstruct()
{
	EndGameInstance = Cast<UEndGameInstance>(GetGameInstance());
	if (!EndGameInstance)
	{
		UE_LOG(LogTemp, Error, TEXT("Have to use the correct game instance"));
	}
}

void UResultsScreen::NativeConstruct()
{
	Super::NativeConstruct();
	RestartButton->BackgroundButton->OnClicked.AddDynamic(EndGameInstance, &UEndGameInstance::ReloadLevel);
	MainMenuButton->BackgroundButton->OnClicked.AddDynamic(EndGameInstance, &UEndGameInstance::LoadMainMenu);
}

void UResultsScreen::SetWin()
{
	ResultsSwitch->SetActiveWidgetIndex(1);
	ButtonBox->SetVisibility(ESlateVisibility::Hidden);
}

void UResultsScreen::SetLose()
{
	ResultsSwitch->SetActiveWidgetIndex(0);
	ButtonBox->SetVisibility(ESlateVisibility::Visible);
}
