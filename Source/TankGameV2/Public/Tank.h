// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Public/TankAimingComponent.h"
#include "Tank.generated.h"

//Forward Declarations
class AProjectile;
class UTankBarrel; 
class UTankTurret;
class UTankTrack;
class UTankAimingComponent; 
class UPointLightComponent;

//Manages the Tank pawn macro behavior
UCLASS()
class TANKGAMEV2_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	//Needs a static mesh assigned in tank_bp
	UFUNCTION(BlueprintCallable, Category="Setup")
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	//Needs a static mesh assigned in tank_bp
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetTrackReference(UTankTrack* TrackToSet);

	//Needs a static mesh assigned in tank_bp
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTurretReference(UTankTurret* TurretToSet);
	
	//Needs a static mesh assigned in tank_bp
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetPointLightReference(UPointLightComponent* LightToSet);


	//
	UFUNCTION(BlueprintCallable, Category = "Controls")
	void FireCannon();


	void AimAt(FVector OutHitLocation);

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		FVector BarrelStartLocation;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 2.25;

	double LastFiretime = 0.0;

	UTankTrack* Track = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;

private:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 160000.0; //TODO - Find sensible default

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint; 

	UTankBarrel* Barrel = nullptr;

	UPointLightComponent* PointLightSet = nullptr;
};
