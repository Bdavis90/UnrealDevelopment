// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/BindVariable.h"
#include "../../EngineDevelopment.h"

// Sets default values
ABindVariable::ABindVariable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VisiblInstanceOnlyOdd = 3;
	EditAnywhere = 0.42f;
}

// Called when the game starts or when spawned
void ABindVariable::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(Game, Error, TEXT("Actor's Name is %s"), *GetName());
	UE_LOG(Game, Warning, TEXT("Int is %d and float is %f"), VisiblInstanceOnlyOdd, EditAnywhere);
	UE_LOG(Game, Display, TEXT("Vel %s"), *GetVelocity().ToString());
}

// Called every frame
void ABindVariable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

