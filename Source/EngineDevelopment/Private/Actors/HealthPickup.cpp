// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/HealthPickup.h"
#include "Kismet/GameplayStatics.h"
#include "Actors/BasePlayer.h"

//void AHealthPickup::HandleNoPickup()
//{
//	UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation());
//}
//
void AHealthPickup::HandlePostPickup()
{
	Destroy();
}

bool AHealthPickup::ShouldActivate(AActor* Other) const
{
	return Cast<ABasePlayer>(Other)->CanPickupHealth();
}
