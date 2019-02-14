// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:


	virtual void Tick(float DeltaTime) override;


	// Start the tank moving the barrel so that a shot would it where
	virtual void BeginPlay() override;
	
private:
	// the crosshair intersects the world
	void AimTowardsCrosshair();
	
	ATank* GetControlledTank() const;

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation)  const;

	bool GetLookHitVectorLocation(FVector LookDirection, FVector & HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
};
