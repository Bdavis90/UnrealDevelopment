// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePickup.h"
#include "Components/BoxComponent.h"

// Sets default values
ABasePickup::ABasePickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

		Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
		SetRootComponent(Collision);

		Collision->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::HandleOverlap);

}

// Called when the game starts or when spawned
void ABasePickup::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePickup::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (ShouldActivate(OtherActor))
	{
		HandlePickup(OtherActor, SweepResult);
		HandlePostPickup();
	}
	//else
	//{
	//	HandleNoPickup();
	//}
}


void ABasePickup::HandlePickup(AActor* OtherActor, FHitResult SweepResult)
{

}

void ABasePickup::HandlePostPickup()
{
	Destroy();
}

bool ABasePickup::ShouldActivate(AActor* OtherActor) const
{
	return true;
}
