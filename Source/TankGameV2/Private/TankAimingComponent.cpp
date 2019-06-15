// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankAimingComponent.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Public/TankBarrel.h"
#include "Public/TankTurret.h"
#include "Engine/EngineTypes.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;				//SHOULD THIS TICK???

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
	if (!Barrel) {
		UE_LOG(LogTemp, Error, TEXT("Failed to find a barrel on %s"), *(GetOwner()->GetName()))
	}
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
	UE_LOG(LogTemp, Error, TEXT("Failed to find a barrel on %s"), *(GetOwner()->GetName()))
}

// Called when the game starts


void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LaunchSpeed)
{
	if (!Barrel || !Turret)
	{
		return;
	}
	FVector OutLaunchVelocity;
	FVector BarrelStartLocation = Barrel->GetSocketLocation(FName("FiringPoint"));

	//Calculate launch velocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		BarrelStartLocation,
		WorldSpaceAim,
		LaunchSpeed,
		false,
		0,
		0
		,ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		
		MoveBarrel(AimDirection);
		MoveTurret(AimDirection);
	}	
	else
	{
		auto thisTime = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f NO AIM SOLVE FOUND"), thisTime)
	}

}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotation;

	Barrel->Elevate(DeltaRotator.Pitch); // Relative speed float passed into Elevate is a scalar on the MaxDegreesPerSecond value in TankBarrel.h
}

void UTankAimingComponent::MoveTurret(FVector AimAzimuth)
{
	auto TurretRotation = Turret->GetForwardVector().Rotation();
	auto RotateAsRotator = AimAzimuth.Rotation();
	auto DeltaAzimuth = RotateAsRotator - TurretRotation;

	Turret->RotateAzimuth(DeltaAzimuth.Yaw);
}