// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FindPointTask.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEDEVELOPMENT_API UFindPointTask : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Nav")
	float Radius = 1000.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "AI|Nav")
		FBlackboardKeySelector OutputVector;

	FString GetStaticDescription() const;

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
