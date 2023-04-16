// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/ActorWithInterfaces.h"

// Sets default values
AActorWithInterfaces::AActorWithInterfaces()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorWithInterfaces::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorWithInterfaces::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorWithInterfaces::BlueprintCallable()
{
	UE_LOG(LogTemp, Warning, TEXT("C++ BlueprintCallable"));
}

