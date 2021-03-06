// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ONTHERUN_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* TriggerPlate;

	UPROPERTY(EditAnywhere)
	AActor* TriggeringActor;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.f;

	float DoorLastOpenTime;
	AActor* Player;
	AActor* Owner;

	void Open();
	void Close();
};
