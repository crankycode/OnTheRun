// Fill out your copyright notice in the Description page of Project Settings.

#include "OnTheRun.h"
#include "ItemName.h"


// Sets default values for this component's properties
UItemName::UItemName()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UItemName::BeginPlay()
{
	Super::BeginPlay();
	CollisionActor = GetWorld()->GetFirstPlayerController();
	
	

	// ...
	
}

// Called every frame
void UItemName::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	
	// ...
}

void UItemName::DisplayName()
{
	
}

