// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "Engine/World.h"


void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();

	Throttle = FMath::Clamp<float>(Throttle, -1, 1);
	UE_LOG(LogTemp, Warning, TEXT("%s throttle of %f"), *Name, Throttle)
	
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);



	//TODO Clamp the throttle value to 1, need a scalar


}

