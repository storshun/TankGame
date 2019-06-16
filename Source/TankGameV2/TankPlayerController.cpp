// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "GameFramework/PlayerController.h"
#include "Public/Tank.h"
#include "Public/Math/Vector2D.h"
#include "Engine/World.h"
#include "Camera/PlayerCameraManager.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"))
	
	auto PossessedTank = GetControlledTank();
	
	if (!PossessedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("GetControlledTank is null"))
	}
	/*else
	{
		UE_LOG(LogTemp, Warning, TEXT("GetControlledTank returns %s"), *(GetControlledTank()->GetName()))
	}*/
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{

	//Start the tank moving the barrel so that a shot would hit where the cross hair intersects the world
	
	if (!GetControlledTank())	{return;}

	FVector OutHitLocation; //OUT parameter

		if (GetSightRayHitLocation(OutHitLocation))
		{
			GetControlledTank()->AimAt(OutHitLocation);
			//UE_LOG(LogTemp, Warning, TEXT("Look Direction is %s"), *(OutHitLocation.ToString()))
		}
}


//Get world location of line trace through cross hair
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{

	OutHitLocation = FVector(1.0);
	FVector LookDirection;

	//locate the cross hair in the camera view frustum
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D((ViewportSizeX * CrossHairXLocation), (ViewportSizeY * CrossHairYLocation));

	//"De-project" the cross hair to a world direction
	if (GetLookDirection(ScreenLocation, LookDirection)) 
	{
	
		//UE_LOG(LogTemp, Warning, TEXT("World Direction: %s"), *(LookDirection.ToString()))
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	
	}
	
	//write out the vector of the hit location to HitLocation;
	return true;
		
}

bool ATankPlayerController::GetLookDirection(FVector2D& ScreenLocation, FVector& LookDirection) const
{
	FVector PlayerCameraLocation;
	if (DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		PlayerCameraLocation,
		LookDirection
	))
	{
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not deproject screen to world"))
		return false;
	}
}


bool ATankPlayerController::GetLookVectorHitLocation(FVector& LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto BarrelStartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = BarrelStartLocation + (LookDirection * LineTraceRange);
// 
 	if (GetWorld()->LineTraceSingleByChannel(HitResult, BarrelStartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		OutHitLocation = HitResult.Location;
		return true;
 	}
 	else
 	{
 		return false;
 	}
}
