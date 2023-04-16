
// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"


ABaseAIController::ABaseAIController()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseAIController::UpdatePerception);
}

void ABaseAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	RunBehaviorTree(BasicAIBehaviorTree);
}

void ABaseAIController::UpdatePerception(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
		Blackboard->SetValueAsObject(PlayerKey, Actor);
	}
	else
	{
		Blackboard->ClearValue(PlayerKey);
	}
}