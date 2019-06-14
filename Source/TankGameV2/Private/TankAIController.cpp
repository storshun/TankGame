// Fill out your copyright notice in the Description page of Project Settings.



#include "Public/TankAIController.h"
#include "Public/Tank.h"
#include "GameFramework/Actor.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("No Player Tank Found!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("---------- Found Player Tank %s"), *PlayerTank->GetName())
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto FoundPlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!FoundPlayerTank)
	{
		return nullptr;
	}
	return Cast<ATank>(FoundPlayerTank);
}
ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());

}
