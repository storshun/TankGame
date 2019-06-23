// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/*
Used to set the maximum driving force and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKGAMEV2_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category="Setup")
	void SetThrottle(float Throttle);

	//max force in newtons
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float TrackMaxDrivingForce = 4000000; //assuming 10m/s^2 (1g acceleration)
};
