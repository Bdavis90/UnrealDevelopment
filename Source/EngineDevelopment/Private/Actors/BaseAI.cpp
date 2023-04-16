// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseAI.h"
#include "Actors/BaseWeapon.h"

void ABaseAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseAI::Shoot()
{
	CurrentWeapon->Shoot();
}



