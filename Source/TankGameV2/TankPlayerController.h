// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankPlayerController.generated.h"

//Forward Declarations
class ATank;

//Manages the player controller input behavior and macro player game behavior
UCLASS()
class TANKGAMEV2_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;

	void BeginPlay() override;

	void AimTowardsCrosshair();

	virtual void Tick(float DeltaTime) override;

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D& ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector& LookDirection, FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly, Category = "Screen Meta Data")
		float CrossHairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly, Category = "Screen Meta Data")
		float CrossHairYLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly, Category = "Screen Meta Data")
		float LineTraceRange = 1000000.0f;

};
