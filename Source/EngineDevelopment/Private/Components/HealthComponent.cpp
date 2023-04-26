// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"
#include "DamageTypes/DamageTypeFire.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	SetStartHealth();
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleDamage);
		
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::SetStartHealth()
{
	Current = Max;
}

void UHealthComponent::HandleDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	Current = FMath::Clamp<float>(Current - Damage, 0, Max);

	if (DamageType->IsA<UDamageTypeFire>())
	{
		//UDamageTypeFire* Fire = Cast<UDamageTypeFire>(DamageType->GetClass()->GetDefaultObject());
		//if (Fire)
		//	Fire->StartEffect(DamagedActor, DamageCauser);
	}

	if (Current > 0)
	{
		if (Damage > 0)
		{
			OnDamage.Broadcast(Current / Max);
		}
		else
		{
			OnHealthGained.Broadcast(Current / Max);
		}
		return;
	}

	GetOwner()->OnTakeAnyDamage.RemoveDynamic(this, &UHealthComponent::HandleDamage);
	OnDeath.Broadcast(0);
}

bool UHealthComponent::IsFullHealth() const
{
	if (Current / Max > .99)
		return true;

	return false;
}

