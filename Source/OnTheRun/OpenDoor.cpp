// Fill out your copyright notice in the Description page of Project Settings.

#include "OnTheRun.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	//UE_LOG(LogTemp, Warning, TEXT("The Owner name is %s"), *OwnerName);
	// ...
	
}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	
	// Poll the Trigger Volume
	// If ActorThatTrigger is in the volume
	//if (TriggerPlate->IsOverlappingActor(TriggeringActor))
	//{
	//	Open();
	//	DoorLastOpenTime = GetWorld()->GetTimeSeconds();
	//}

	//// Check to see if its time to close door
	//if (GetWorld()->GetTimeSeconds() - DoorLastOpenTime > DoorCloseDelay)
	//{
	//	Close();
	//}
}

void UOpenDoor::Close()
{
	// Set door rotation to close
	Owner->SetActorRotation(FRotator(.0f, .0f, .0f));
}


void UOpenDoor::Open()
{
	// Set door rotation open
	Owner->SetActorRotation(FRotator(.0f, OpenAngle, .0f));
}

