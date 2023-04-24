// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseAI.h"
#include "Actors/BaseWeapon.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BrainComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void ABaseAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseAI::Shoot()
{
	CurrentWeapon->Shoot();
}

void ABaseAI::Reload()
{
	CharacterReload();
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();
	CurrentWeapon->Reload();
}

void ABaseAI::CharacterDeath(float _Ratio)
{
	Super::CharacterDeath(_Ratio);
	UAIBlueprintHelperLibrary::GetAIController(this)->BrainComponent->StopLogic("AI was killed!");
}

void ABaseAI::CharacterDeathFinished()
{
	Super::CharacterDeathFinished();
	Destroy();
}

void ABaseAI::CharacterAmmoChanged(float Current, float Max)
{
	Super::CharacterAmmoChanged(Current, Max);

	AAIController* AIController = GetController<AAIController>();
	UBlackboardComponent* BlackBoardComponent = AIController->GetBlackboardComponent();
	BlackBoardComponent->SetValueAsFloat(TEXT("Ammo"), Current);
}

void ABaseAI::CharacterWeaponActionEnded()
{
	Super::CharacterWeaponActionEnded();
	UAIBlueprintHelperLibrary::SendAIMessage(this, TEXT("ActionFinished"), nullptr);
}



