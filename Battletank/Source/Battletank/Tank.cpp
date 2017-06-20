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
	InputComponent->BindAxis("Rotate_Turret", this, &ATank::RotateTurret);
	InputComponent->BindAxis("Rotate_Barrel", this, &ATank::RotateBarrel);
	InputComponent->BindAxis("Rotate_Tank", this, &ATank::RotateTank);
	InputComponent->BindAxis("Move_Tank", this, &ATank::MoveTank);

}

void ATank::RotateTurret(float speed)
{
	if (!Turret) { return; }
	float Rotation;
	Rotation = GetWorld()->DeltaTimeSeconds * speed * RotationSpeed;
	Turret->AddWorldRotation(FRotator(0.0f, Rotation, 0.0f));
}
void ATank::RotateBarrel(float speed)
{
	if (!Barrel) { return; }
	float Rotation;
	Rotation = GetWorld()->DeltaTimeSeconds * speed * RotationSpeed;
	Barrel->AddWorldRotation(FRotator(Rotation, 0.0f, 0.0f));
}
void ATank::RotateTank(float speed)
{
	if (!Body) { return; }
	float Rotation;
	Rotation = GetWorld()->DeltaTimeSeconds * speed * RotationSpeed;
	Body->AddWorldRotation(FRotator(0.0f,Rotation, 0.0f));
}
void ATank::MoveTank(float speed)
{
	if (!Body) { return; }
	float Distance;
	Distance = GetWorld()->DeltaTimeSeconds * speed * MovementSpeed;
	Body->AddRelativeLocation(Body->GetForwardVector() * Distance);
	//Body->AddWorldLocation();
}



void ATank::SetTurretChildActor(UStaticMeshComponent * TurretFromBP)
{
		Turret = TurretFromBP;
}
void ATank::SetBodyChildActor(UStaticMeshComponent * BodyFromBP)
{
		Body = BodyFromBP;
}
void ATank::SetBarrelChildActor(UStaticMeshComponent * BarrelFromBP)
{
	    Barrel = BarrelFromBP;
}
