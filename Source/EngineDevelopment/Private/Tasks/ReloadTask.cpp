// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/ReloadTask.h"
#include "Actors/BaseAI.h"
#include "AIController.h"

EBTNodeResult::Type UReloadTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABaseAI* AI = Cast<ABaseAI>(OwnerComp.GetAIOwner()->GetPawn());
	if (AI)
	{
		AI->Reload();
		WaitForMessage(OwnerComp, TEXT("ActionFinished"));
		//FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		//return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
