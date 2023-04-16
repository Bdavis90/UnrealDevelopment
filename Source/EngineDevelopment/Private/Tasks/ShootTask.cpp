// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/ShootTask.h"
#include "AIController.h"
#include "Actors/BaseAI.h"

EBTNodeResult::Type UShootTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABaseAI* AI = Cast<ABaseAI>(OwnerComp.GetAIOwner()->GetPawn());
	if (AI)
	{
		AI->Shoot();
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
