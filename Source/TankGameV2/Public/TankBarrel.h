// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

//Manages the barrel behavior of the tanks
UCLASS( meta = (BlueprintSpawnableComponent))
class TANKGAMEV2_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//-1 is max downward movement, and +1 is max upward movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = BarrelCharacteristics)
		float MaxBarrelAngleChangePerSecond = 3.0;

	UPROPERTY(EditAnywhere, Category = BarrelCharacteristics)
		float MaxElevationAngle = 40.0;

	UPROPERTY(EditAnywhere, Category = BarrelCharacteristics)
		float MinElevationDegrees = -2.0;
};
