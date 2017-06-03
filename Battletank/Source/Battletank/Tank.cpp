// Fill out your copyright notice in the Description page of Project Settings.

#include "Battletank.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("Turret_Clockwise", IE_Pressed, this, &ATank::RotateTurret);
	InputComponent->BindAction("Turret_CounterClockwise", IE_Pressed, this, &ATank::RotateTurret);
}

void ATank::RotateTurret()
{
	UE_LOG(LogTemp, Warning, TEXT("RotateTurret Called"));
	if (!Turret) { return; }
	Turret->SetWorldRotation(FRotator(0.0f, 10.0f, 0.0f));
		
}

void ATank::SetTurretChildActor(UChildActorComponent * TurretFromBP)
{
	UE_LOG(LogTemp, Warning, TEXT("SetTturretChildActor Called"));
		Turret = TurretFromBP;
}
