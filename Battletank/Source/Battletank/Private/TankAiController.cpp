// Fill out your copyright notice in the Description page of Project Settings.

#include "Battletank.h"
#include "TankAiController.h"




ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank not possessing tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank possessing : %s"), *(PlayerTank->GetName()))
	}
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp,Warning,TEXT("ticking"));
	AimTowardsCrosshair();
}


ATank * ATankAiController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}

void ATankAiController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("hitlocation : %s"), *HitLocation.ToString());
	}
}
bool ATankAiController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	//GetWorld()->GetGameViewport()->GetResourceSize();
	//GetViewportSize(ViewportSizeX, ViewportSizeY);

	return false;
}