// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankBarrel.h"
#include "Engine/World.h"
#include "Public/Math/UnrealMathUtility.h"
#include "Components/ActorComponent.h"


void UTankBarrel::Elevate(float RelativeSpeed) {

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxBarrelAngleChangePerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	//UE_LOG(LogTemp, Warning, TEXT("Desired Angle is %f"), RawNewElevation)
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationAngle);
	
	
	//UE_LOG(LogTemp, Warning, TEXT("Clamped Angle is %f"), Elevation)
	SetRelativeRotation(FRotator(Elevation, 0, 0));
	
}