// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GunActor.generated.h"

class AProjectile;
class ABallProjectile;

UCLASS()
class ONTHERUN_API AGunActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void FireWeapon(USkeletalMeshComponent* GunSkeletal);

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 100000; // TODO find sensible default
	
	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<ABallProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* FireSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Gameplay)
	class UAnimInstance* AnimInstance;

};
