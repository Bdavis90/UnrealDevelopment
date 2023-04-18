// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeGameMode.h"
#include "Actors/BasePlayer.h"
#include "GameInstances/ENDGameInstance.h"
#include "Widgets/ResultsScreen.h"
#include "Actors/BaseAI.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"

void ACodeGameMode::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(this, ABaseAI::StaticClass(), OutActors);

	NumberOfEnemies = OutActors.Num();

	for (auto Enemy : OutActors)
	{
		Enemy->OnDestroyed.AddDynamic(this, &ACodeGameMode::EnemyDestoryed);
	}

	AActor* BaseActor = UGameplayStatics::GetActorOfClass(GetWorld(), ABasePlayer::StaticClass());
	ActivePlayer = Cast<ABasePlayer>(BaseActor);
	ActivePlayer->OnPlayerDied.AddDynamic(this, &ACodeGameMode::PlayerDestoryed);

	AActor* PlayerController = UGameplayStatics::GetActorOfClass(GetWorld(), PlayerControllerClass);
	ActivePC = Cast<APlayerController>(PlayerController);
	ActivePC = GetWorld()->GetFirstPlayerController();

	if (ResultsClass) {
		ResultsWidget = CreateWidget<UResultsScreen>(GetWorld()->GetFirstPlayerController(), ResultsClass);
	}

	GameInstance = Cast<UEndGameInstance>(GetGameInstance());
	if (!GameInstance)
	{
		UE_LOG(LogTemp, Error, TEXT("WrongGameInstance"));
	}
}

void ACodeGameMode::EnemyDestoryed(AActor* DestroyedActor)
{
	NumberOfEnemies--;
	//I always like to have this check just in case soemthign causes it to jump below 0
	if (NumberOfEnemies <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Killed all enemies, whould win the game now!"));
		ResultsWidget->SetWin();
		Cast<UUserWidget>(ResultsWidget)->AddToViewport();
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, GameInstance, &UEndGameInstance::LoadMainMenu, TimeToSeeWinScreen, false);
		ActivePlayer->WonLevel();
	}
}

void ACodeGameMode::PlayerDestoryed()
{
	ResultsWidget->SetLose();
	ActivePC->SetShowMouseCursor(true);
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(ActivePC, nullptr, EMouseLockMode::LockAlways);
	ResultsWidget->AddToViewport();
}