// Fill out your copyright notice in the Description page of Project Settings.

#include "OnTheRun.h"
#include "RifleActor.h"
#include "BallProjectile.h"
#include "Animation/AnimInstance.h"




// Sets default values
ARifleActor::ARifleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	
	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

}

// Called when the game starts or when spawned
void ARifleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARifleActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ARifleActor::OnFire()
{
	if (ProjectileClass != NULL)
	{
		const FRotator SpawnRotation = FP_MuzzleLocation->GetComponentRotation();

		const FVector SpawnLocation = FP_MuzzleLocation->GetComponentLocation();

		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			// spawn the projectile at the muzzle
			World->SpawnActor<ABallProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
		}
	}
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

	//// Now send a trace from the end of our gun to see if we should hit anything
	//APlayerController* PlayerController = Cast<APlayerController>(GetController());

	//// Calculate the direction of fire and the start location for trace
	//FVector CamLoc;
	//FRotator CamRot;
	//PlayerController->GetPlayerViewPoint(CamLoc, CamRot);
	//const FVector ShootDir = CamRot.Vector();

	//FVector StartTrace = FVector::ZeroVector;
	//if (PlayerController)
	//{
	//	FRotator UnusedRot;
	//	PlayerController->GetPlayerViewPoint(StartTrace, UnusedRot);

	//	// Adjust trace so there is nothing blocking the ray between the camera and the pawn, and calculate distance from adjusted start
	//	StartTrace = StartTrace + ShootDir * ((GetActorLocation() - StartTrace) | ShootDir);
	//}

	//// Calculate endpoint of trace
	//const FVector EndTrace = StartTrace + ShootDir * WeaponRange;

	//// Check for impact
	//const FHitResult Impact = WeaponTrace(StartTrace, EndTrace);

	//// Deal with impact
	//AActor* DamagedActor = Impact.GetActor();
	//UPrimitiveComponent* DamagedComponent = Impact.GetComponent();

	//// If we hit an actor, with a component that is simulating physics, apply an impulse
	//if ((DamagedActor != NULL) && (DamagedActor != this) && (DamagedComponent != NULL) && DamagedComponent->IsSimulatingPhysics())
	//{
	//	DamagedComponent->AddImpulseAtLocation(ShootDir*WeaponDamage, Impact.Location);
	//}
}

