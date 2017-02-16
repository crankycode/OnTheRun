// Fill out your copyright notice in the Description page of Project Settings.


#include "OnTheRun.h"
#include "OnTheRunCharacter.h"
#include "TableType.h"


// Sets default values for this component's properties
UTableType::UTableType()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTableType::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	// ...
	
}


// Called every frame
void UTableType::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	

	//if (TriggerPlate->IsOverlappingActor(Player))
	//{
	//	//UE_LOG(LogTemp, Warning, TEXT("Player OverlapBegin"))
	//	Cast<AOnTheRunCharacter>(Player)->TableOverlap = true;
	//}
	//else
	//{
	//	Cast<AOnTheRunCharacter>(Player)->TableOverlap = false;
	//}
	
}

void UTableType::OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// OtherActor is the actor that triggered the event. Check that is not ourself 
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player OverlapBegin"))
	}
}