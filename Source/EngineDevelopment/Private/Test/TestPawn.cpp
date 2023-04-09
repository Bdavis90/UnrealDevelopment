// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/TestPawn.h"
#include "../../EngineDevelopment.h"

// Sets default values
ATestPawn::ATestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestPawn::BeginPlay()
{
	Super::BeginPlay();
	FActorSpawnParameters Params;
	Params.Owner = GetController();
	Params.Instigator = this;
	GetWorld()->SpawnActor<AActor>(ClassType, FTransform(), Params);
}

// Called every frame
void ATestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &ATestPawn::InputHappened);

}

void ATestPawn::InputHappened()
{
	UE_LOG(Game, Error, TEXT("Input Happened"));
	TSubclassOf<ATestPawn> ClassRef;
	ClassRef = ATestPawn::StaticClass();
	FActorSpawnParameters Params;
	Params.Owner = GetController();
	Params.Instigator = this;
	GetWorld()->SpawnActor<AActor>(ClassRef, FTransform(), Params);
}

