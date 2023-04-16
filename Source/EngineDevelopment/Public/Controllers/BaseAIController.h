 //Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "BaseAIController.generated.h"

/**
 *
 */
UCLASS()
class ENGINEDEVELOPMENT_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

protected:
		ABaseAIController();

		void OnPossess(APawn* InPawn) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Task")
		UBehaviorTree* BasicAIBehaviorTree;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Perception")
		UAIPerceptionComponent* AIPerception;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Task")
		FName PlayerKey = TEXT("Player");

	UFUNCTION()
		void UpdatePerception(AActor* Actor, FAIStimulus Stimulus);


};

