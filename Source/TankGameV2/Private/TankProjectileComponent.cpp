// Fill out your copyright notice in the Description page of Project Settings.


#include "TankProjectileComponent.h"

// Sets default values for this component's properties
UTankProjectileComponent::UTankProjectileComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankProjectileComponent::BeginPlay()
{
	Super::BeginPlay();
	bAutoActivate = false;

	// ...
	
}


// Called every frame
void UTankProjectileComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

