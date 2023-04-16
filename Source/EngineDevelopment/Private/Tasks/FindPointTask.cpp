// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/FindPointTask.h"
#include "GameplayTask.h"
#include "NavigationSystem.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

FString UFindPointTask::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector: %s"), *OutputVector.SelectedKeyName.ToString());
}

EBTNodeResult::Type UFindPointTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());

	FNavLocation RoamLocation;
	FVector Origin = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();

	if (IsValid(NavSystem) && NavSystem->GetRandomPointInNavigableRadius(Origin, Radius, RoamLocation))
	{
		UBlackboardComponent* BlackBoardComponent = OwnerComp.GetBlackboardComponent();
		BlackBoardComponent->SetValueAsVector(OutputVector.SelectedKeyName, RoamLocation.Location);
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}

	UE_LOG(LogTemp, Warning, TEXT("Could not find a roam location"));
	return EBTNodeResult::Failed;

}
