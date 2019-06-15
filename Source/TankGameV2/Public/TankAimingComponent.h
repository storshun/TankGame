// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComponent.generated.h"

//Forward Declaration
class UTankBarrel; 
class UTankTurret;

//Holds Parameters for tank aiming behavior
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class TANKGAMEV2_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurretToSet);

public:	

	void AimAt(FVector WorldSpaceAim, float LaunchSpeed);
		
private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrel(FVector AimDirection);
	void MoveTurret(FVector AimAzimuth);
	//UPROPERTY(EditAnywhere,Category=BarrelCharacteristics)
	//float ElevationRate = 5.0;

};
