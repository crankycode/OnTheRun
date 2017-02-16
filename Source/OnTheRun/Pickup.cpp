// Fill out your copyright notice in the Description page of Project Settings.

#include "OnTheRun.h"
#include "Pickup.h"


#define OUT
// Sets default values for this component's properties
UPickup::UPickup()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPickup::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
	
	// ...
	
}


// Called every frame
void UPickup::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	
	// Get Player view point this tick
	//GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
	//	OUT PlayerViewPointLocation,
	//	OUT PlayerViewPointRotation
	//);

	//UE_LOG(LogTemp, Warning, TEXT("The current view %s"),*(PlayerViewPointLocation.ToString()));
	//UE_LOG(LogTemp, Warning, TEXT("Current Direction: %s"), *GetOwner()->GetActorForwardVector().ToString());
	
	PlayerViewPointLocation = GetOwner()->GetActorForwardVector();
	PlayerViewPointRotation = GetOwner()->GetActorForwardVector().Rotation();

	// ...
}

