// Fill out your copyright notice in the Description page of Project Settings.



#include "Public/TankAIController.h"
#include "Public/Tank.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto FoundPlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!FoundPlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI CAN'T FIND THE PLAYER TANK"))

		return;
	}
	
	auto AIControlledtank = Cast<ATank>(GetPawn());
	AIControlledtank->AimAt(FoundPlayerTank->GetActorLocation());


		AIControlledtank->FireCannon();
}


