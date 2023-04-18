// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseAI.h"
#include "Actors/BaseWeapon.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BrainComponent.h"
#include "AIController.h"

void ABaseAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseAI::Shoot()
{
	CurrentWeapon->Shoot();
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



