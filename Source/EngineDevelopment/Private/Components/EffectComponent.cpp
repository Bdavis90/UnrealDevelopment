// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/EffectComponent.h"
#include "Actors/EffectsFire.h"

// Sets default values for this component's properties
UEffectComponent::UEffectComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEffectComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEffectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEffectComponent::StartEffect(EDamageEffects Type, AActor* DamageCauser)
{
	FActorSpawnParameters params;
	params.Owner = DamageCauser;
	AActor* Actor;
	switch (Type)
	{
	case EDamageEffects::Fire:
		Actor = GetWorld()->SpawnActor<AActor>(FireEffect, GetComponentTransform().GetLocation(), GetComponentRotation(), params);
		if (Actor)
			Actor->AttachToActor(GetOwner(), FAttachmentTransformRules::KeepRelativeTransform);
		else
			UE_LOG(LogTemp, Error, TEXT("Actor could not be spawned!"));
		break;

	default:
		break;
	}
}

