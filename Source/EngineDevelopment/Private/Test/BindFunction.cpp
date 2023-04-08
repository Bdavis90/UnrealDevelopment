// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/BindFunction.h"
#include "../../EngineDevelopment.h"

// Sets default values
ABindFunction::ABindFunction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Value = 0.65f;
}

// Called when the game starts or when spawned
void ABindFunction::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABindFunction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABindFunction::BlueprintCallable()
{
	UE_LOG(Game, Warning, TEXT("in C++ BlueprintCallable"));
}

void ABindFunction::BlueprintNativeEvent_Implementation()
{
	UE_LOG(Game, Error, TEXT("in C++ BlueprintNativeEvent_Implementation"));
}

float ABindFunction::Pure() const
{
	return Value;
}

