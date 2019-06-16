// Fill out your copyright notice in the Description page of Project Settings.



#include "Public/TankAIController.h"
#include "Public/Tank.h"
#include "Engine/World.h"
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
		auto AITankName = GetAIControlledTank()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s Found Player Tank %s"), *AITankName,*PlayerTank->GetName())
	}
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player Tank is %s"), *(GetPlayerTank()->GetName()))
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("CAN'T FIND THE PLAYER TANK"))
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

