// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BindVariable.generated.h"

UCLASS()
class ENGINEDEVELOPMENT_API ABindVariable : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABindVariable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Read Only
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Variable|ReadOnly")
	bool VisibleAnywhere;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Variable|ReadOnly")
	uint8 VisibleDefaultsOnly;
	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly, Category = "Variable|ReadOnly|Odd")
	int32 VisiblInstanceOnlyOdd;
	UPROPERTY(VisibleInstanceOnly, Category = "Variable|ReadOnly")
	int32 VisibleInstanceOnly;

	//Read Write
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variable|ReadWrite")
	float EditAnywhere;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Variable|ReadWrite|Odd")
	FName EditDefaultsOnlyOdd;
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Variable|ReadWrite|Odd")
	FString EditInstanceOnlyOdd;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Variable|ReadWrite")
	FText EditDefaultsOnly;
	UPROPERTY(EditInstanceOnly, Category = "Variable|ReadWrite")
	FString EditInstanceOnly;

	//Array
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<int32> ValArray;
};
