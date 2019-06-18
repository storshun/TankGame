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
class UTankAimingComponent; 

//Manages the Tank pawn macro behavior
UCLASS()
class TANKGAMEV2_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	
	UFUNCTION(BlueprintCallable, Category="Setup")

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")

	void SetTurretReference(UTankTurret* TurretToSet);
	
	UFUNCTION(BlueprintCallable, Category = "Controls")

	void FireCannon();


	void AimAt(FVector OutHitLocation);



	UPROPERTY(VisibleAnywhere, Category = "Firing")
		FVector BarrelStartLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;

private:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Firing")
		float LaunchSpeed = 160000.0; //TODO - Find sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint; 

	UTankBarrel* Barrel = nullptr;

};
