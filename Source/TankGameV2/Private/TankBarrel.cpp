// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankBarrel.h"
#include "Engine/World.h"
#include "Components/ActorComponent.h"


void UTankBarrel::Elevate(float RelativeSpeed) {

	
	
}
	//move the turret azimuth to the vector of AimDrection on Yaw/Z Axis
		//move the barrel elevation to the vector of AimDirection on pitch Y axis

		//long term, if the tank is moving, we'll want to orient the body to align with the barrel
		//if motion forward or backward
			//speed up appropriate tank tread and/or reverse appropriate tread