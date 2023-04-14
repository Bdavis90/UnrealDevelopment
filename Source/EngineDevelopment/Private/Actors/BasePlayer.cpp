// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "../../EngineDevelopment.h"
#include "Widgets/MyUserWidget.h"
#include "Components/HealthComponent.h"

ABasePlayer::ABasePlayer()
{
	SpringArm = CreateDefaultSubobject <USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);


}

void ABasePlayer::CharacterDeath(float Ratio)
{
	Super::CharacterDeath(Ratio);
	DisableInput(PlayerController);
}

void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayerController>(GetController());
	if (!PlayerController)
	{
		UE_LOG(Game, Error, TEXT("Need player controller for HUD"));
		return;
	}
	HUD = CreateWidget<UMyUserWidget>(PlayerController, WidgetClass);
	HUD->AddToViewport();

	HealthComponent->OnDamage.AddDynamic(this, &ABasePlayer::SetHealth);
	HealthComponent->OnDeath.AddDynamic(this, &ABasePlayer::SetHealth);
}

void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("TurnTo", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("MoveForward", this, &ABasePlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABasePlayer::MoveRight);
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &ABaseCharacter::CharacterShoot);
}

void ABasePlayer::MoveForward(float Value)
{
	FRotator MakeRotation = FRotator(0.f, GetControlRotation().Yaw, 0.f);

	AddMovementInput(MakeRotation.Vector(), Value);
}

void ABasePlayer::MoveRight(float Value)
{
	FRotator MakeRotation = FRotator(0.f, GetControlRotation().Yaw, 0.f);

	AddMovementInput(FRotationMatrix(MakeRotation).GetScaledAxis(EAxis::Y), Value);
}

void ABasePlayer::SetHealth(float Ratio)
{
	HUD->SetHealth(Ratio);
}



