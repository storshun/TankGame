// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"
#include "Engine/World.h"
#include "Public/Math/UnrealMathUtility.h"
#include "Components/ActorComponent.h"


void UTankTurret::RotateAzimuth(float RelativeSpeed)
{

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto AzimuthChange = RelativeSpeed * MaxTurretAngleChange * GetWorld()->DeltaTimeSeconds;
	auto RawAzimuth = RelativeRotation.Yaw + AzimuthChange;

	SetRelativeRotation(FRotator(0, RawAzimuth, 0));
}
