// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "GunActor.h"
#include "GunAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ONTHERUN_API UGunAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGunAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void SetGunReference(AActor* GunToSet, USkeletalMeshComponent* GunSkeletalToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed, AActor* Character);

private:
	AGunActor* Gun = nullptr;
	USkeletalMeshComponent* GunSkeletalMeshComponent = nullptr;
	AActor* CurrentCharacter = nullptr;
	
	void MoveCharacterTowards(FVector AimDirection);
};
