// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/MyUserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/TextBlock.h"

UMyUserWidget::UMyUserWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}


void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UMaterialInterface* Interface = Cast<UMaterialInterface>(Reticle->Brush.GetResourceObject());
	DynamicMaterial = UMaterialInstanceDynamic::Create(Interface, this, TEXT("DynamicMaterial"));
	if (DynamicMaterial)
	{
		Reticle->SetBrushFromMaterial(DynamicMaterial);
		SetMatColor(DefaultColor);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Dynamic Material Not Found"));
	}

}

void UMyUserWidget::SetHealth(float Ratio)
{
	Health->SetPercent(Ratio);
}

void UMyUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	FHitResult Hit;
	FVector StartLocation;

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	TArray<AActor*> IgnoreActors;
	IgnoreActors.Add(GetOwningPlayerPawn());

	GetLinePoints(StartLocation, EndPoint);

	bValidHit = UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), StartLocation, EndPoint, ObjectTypes, false, IgnoreActors, EDrawDebugTrace::None, Hit, true);
	if (bValidHit)
	{
		HitLocation = Hit.Location;
		if (Cast<APawn>(Hit.Actor))
		{
			SetMatColor(DangerColor);
		}
		else
		{
			SetMatColor(DefaultColor);
		}
	}
	else
	{
		SetMatColor(DefaultColor);
	}
}

void UMyUserWidget::SetMatColor(FLinearColor Color)
{
	DynamicMaterial->SetVectorParameterValue(TEXT("Color"), Color);
}

void UMyUserWidget::GetLinePoints(FVector& Start, FVector& End)  const
{
	FGeometry ReticleGeo = Reticle->GetCachedGeometry();
	FVector2D PixelPos;
	FVector2D	ViewportPos;
	FVector WorldLocation;
	FVector WorldDirection;
	USlateBlueprintLibrary::LocalToViewport(GetWorld(), ReticleGeo, FVector2D(0, 0), PixelPos, ViewportPos);
	PixelPos = PixelPos + (ReticleGeo.GetAbsoluteSize() * .5f);
	GetOwningPlayer()->DeprojectScreenPositionToWorld(PixelPos.X, PixelPos.Y, WorldLocation, WorldDirection);

	Start = WorldLocation;
	End = WorldLocation = (WorldDirection * 100000.f);
}

void UMyUserWidget::GetAimedPoint(bool& Valid, FVector& Hit, FVector& End) const 
{
	Valid = bValidHit;
	Hit = HitLocation;
	End = EndPoint;
}

void UMyUserWidget::SetAmmo(float Current, float Max)
{
	
	CurrentAmmo->SetText(FText::AsNumber(Current));
	MaxAmmo->SetText(FText::AsNumber(Max));
}
