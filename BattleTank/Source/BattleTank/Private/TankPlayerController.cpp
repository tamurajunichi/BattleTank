// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ControlledTank is not posseing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ControlledTank is posseing %s"), *ControlledTank->GetName())
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) // Has "Side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
				// Tell controlled tank to aim at this point
	}
}

// Get world location if linetrace through crosshair, true if hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}
