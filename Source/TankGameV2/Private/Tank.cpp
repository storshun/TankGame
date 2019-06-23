// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Tank.h"
#include "Public/TankBarrel.h"
#include "Public/TankTrack.h"
#include "Engine/World.h"
#include "Public/Projectile.h"
#include "Components/PointLightComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//No need to protect pointers as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTrackReference(UTankTrack* TrackToSet)
{
	if (TrackToSet)
	{
		Track = TrackToSet;
	}
	else
	{
		return;
	}

}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::SetPointLightReference(UPointLightComponent* LightToSet)
{
	if (LightToSet)
	{
		PointLightSet = LightToSet;
	}
	else
	{
		return;
	}

}

//Spawn the projectile at the socket location
void ATank::FireCannon()
{
	
	//UE_LOG(LogTemp, Warning, TEXT("Fired!"))

	bool isReloaded = (FPlatformTime::Seconds() - LastFiretime) > ReloadTimeInSeconds;

	if (Barrel && isReloaded) {

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation("FiringPoint"),
			Barrel->GetSocketRotation("FiringPoint"));

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFiretime = FPlatformTime::Seconds();
	}
}
// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector OutHitLocation)
{
	//auto OurTankName = GetName();
	//UE_LOG(LogTemp, Error, TEXT("%s is aiming at %s"), *OurTankName, *(OutHitLocation.ToString()))
	TankAimingComponent->AimAt(OutHitLocation, LaunchSpeed);
}

