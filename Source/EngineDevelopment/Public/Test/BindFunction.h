// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BindFunction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventDispatcher, AActor*, ParamName);

UCLASS()
class ENGINEDEVELOPMENT_API ABindFunction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABindFunction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Function")
	void BlueprintCallable();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Function")
	void BlueprintNativeEvent();
	virtual void BlueprintNativeEvent_Implementation();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Function")
		void BlueprintImplementableEvent();

	//Pure
	float Value;
	UFUNCTION(BlueprintCallable, Category = "Function|Pure")
	float Pure() const;

	//EVentDispatcher
	UPROPERTY(BlueprintCallable, Category = Fucntion)
	FEventDispatcher OnAction;
	UPROPERTY(BlueprintAssignable, Category = Fucntion)
	FEventDispatcher OnAssignable;
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = Fucntion)
	FEventDispatcher OnDefault;
};
