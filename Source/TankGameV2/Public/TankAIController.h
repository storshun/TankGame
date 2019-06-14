// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

//Forward Declarations
class ATank;

//Manages the AI aiming and control behavior
UCLASS()
class TANKGAMEV2_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	ATank* GetAIControlledTank() const;

	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetPlayerTank() const;


};
