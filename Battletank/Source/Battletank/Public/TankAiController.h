// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float) override;
	ATank* GetPlayerTank() const;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;

	
	
};
