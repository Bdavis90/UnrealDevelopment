// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DamagePickup.h"

#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

ADamagePickup::ADamagePickup()
{

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(GetRootComponent());

}

void ADamagePickup::HandlePickup(AActor* OtherActor, FHitResult SweepResult)
{
	if (!DamageTypeClass)
		UE_LOG(LogTemp, Error, TEXT("Damge Type is null!"));
	UGameplayStatics::ApplyDamage(OtherActor, Damage, nullptr, this, DamageTypeClass);
}

void ADamagePickup::HandlePostPickup()
{
}