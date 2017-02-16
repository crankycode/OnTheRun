// Fill out your copyright notice in the Description page of Project Settings.

#include "OnTheRun.h"
#include "Projectile.h"
#include "BallProjectile.h"
#include "GunActor.h"
#include "Animation/AnimInstance.h"

// Sets default values
AGunActor::AGunActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AGunActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGunActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AGunActor::FireWeapon(USkeletalMeshComponent* GunSkeletal)
{
	// Play a sound if there is one
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
	//if (!ProjectileBlueprint) { return; }

	//auto Projectile = GetWorld()->SpawnActor<ABallProjectile>(
	//	ProjectileBlueprint,
	//	GunSkeletal->GetSocketLocation(FName("Projectile")),
	//	GunSkeletal->GetSocketRotation(FName("Projectile"))
	//);


	UE_LOG(LogTemp, Warning, TEXT("Firing Weapon"))
}

