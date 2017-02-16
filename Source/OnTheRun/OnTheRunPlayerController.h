// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "OnTheRunCharacter.h"
#include "OnTheRunPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ONTHERUN_API AOnTheRunPlayerController : public APlayerController
{
	GENERATED_BODY()

		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;

public:
	
	AOnTheRunCharacter* GetControlledPlayer() const;

	// Turn the player towards the crosshair intersects the world
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitDirection(FVector LookDirection, FVector& HitLocation) const;

private:

	UPROPERTY(EditAnywhere)
	int32 LineTraceRange = 1000000;
};
