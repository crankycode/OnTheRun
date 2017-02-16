// Fill out your copyright notice in the Description page of Project Settings.

#include "OnTheRun.h"
#include "OnTheRunPlayerController.h"

class OnTheRunCharacter;
// Tick
	// Super
	// AimTowardsCrosshair()

void AOnTheRunPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}


void AOnTheRunPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//this->Tick = true;
}

AOnTheRunCharacter* AOnTheRunPlayerController::GetControlledPlayer() const
{
	return Cast<AOnTheRunCharacter>(GetPawn());
}

void AOnTheRunPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledPlayer()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		auto OutPlayerName = GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s Hit Location: %s"),*OutPlayerName, *HitLocation.ToString());
		GetControlledPlayer()->AimAt(HitLocation);
		// ToDO Tell controlled tank to aim at this point
	}
	
	// Get world location if linetrace through crosshair
	// If it hits the landscape
		// Tell character to turn towards that point

	// Return an OUT parameter, true if hit landscape

}

bool AOnTheRunPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector LookDirection;
	// "De-project" the screen position of the crosshair to a world direction
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
		// Line-trace along that LookDirection, and see what we hit (up to max range)
		GetLookVectorHitDirection(LookDirection, HitLocation);
		// GetLookVectorHitLocation();

	}
	return true;
}

bool AOnTheRunPlayerController::GetLookVectorHitDirection(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		// Set Hit Location
		return true;
	}
	return false;
}

bool AOnTheRunPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CamaraWorldLocation; // This is for discarding

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CamaraWorldLocation,
		LookDirection
	);
}
