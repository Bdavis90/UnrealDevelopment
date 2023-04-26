// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "EffectComponent.generated.h"


UENUM(BlueprintType)
enum class EDamageEffects : uint8
{
	Fire		UMETA(dispalyname = "Fire"),
	NumEffects	UMETA(displayname = "NumEffects"),

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ENGINEDEVELOPMENT_API UEffectComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEffectComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<class AEffectsFire> FireEffect;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void StartEffect(EDamageEffects Type, AActor* DamageCauser);
};
