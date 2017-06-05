// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

	UFUNCTION(BlueprintCallable)
		void SetTurretChildActor(UChildActorComponent* TurretFromBP);
	UFUNCTION(BlueprintCallable)
		void SetBarrelChildActor(UChildActorComponent* BarrelFromBP);
	UFUNCTION(BlueprintCallable)
		void SetBodyChildActor(UChildActorComponent * BodyFromBP);

private : 
	UChildActorComponent* Turret =nullptr;
	UChildActorComponent* Barrel = nullptr;
	UChildActorComponent* Body = nullptr;

	void RotateTurret(float);
	void RotateBarrel(float);
	void RotateTank(float);
	void MoveTank(float);

	UPROPERTY(EditAnywhere)
		float RotationSpeed;
	UPROPERTY(EditAnywhere)
		float MovementSpeed;
};
