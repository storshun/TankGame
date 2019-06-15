// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

//Manages speed and direction of rotation of the tank pawn's turret
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKGAMEV2_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//-1 is max downward movement, and +1 is max upward movement
	void RotateAzimuth(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = TurretCharacteristics)
		float MaxTurretAngleChange = 7.0;
	
};
