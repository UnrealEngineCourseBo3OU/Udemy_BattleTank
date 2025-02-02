// Fill out your copyright notice in the Description page of Project Settings.

#include "Battletank.h"
#include "TankPlayerController.h"




ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn() );
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
		auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing : %s"), *(ControlledTank->GetName()))
	}
}
