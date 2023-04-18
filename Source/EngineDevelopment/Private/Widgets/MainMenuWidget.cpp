// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/MainMenuWidget.h"
#include "Components/VerticalBox.h"
#include "Widgets/ButtonWidget.h"
#include "GameInstances/EndGameInstance.h"

void UMainMenuWidget::NativePreConstruct()
{
	EndGameInstance = Cast<UEndGameInstance>(GetGameInstance());
}

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (!StartButton)
	{
		UE_LOG(LogTemp, Warning, TEXT("Start button is not set."))
	}
	else if (!QuitButton)
	{
		UE_LOG(LogTemp, Warning, TEXT("Quit button is not set."))
	}

	StartButton->OnButtonClicked.AddDynamic(EndGameInstance, &UEndGameInstance::LoadFirstLevel);
	QuitButton->OnButtonClicked.AddDynamic(EndGameInstance, &UEndGameInstance::QuitGame);
}
