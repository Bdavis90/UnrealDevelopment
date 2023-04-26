// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PickupHelper.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPickupHelper : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ENGINEDEVELOPMENT_API IPickupHelper
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual bool CanPickupHealth() = 0;
};
