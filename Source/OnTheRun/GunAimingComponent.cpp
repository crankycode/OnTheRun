// Fill out your copyright notice in the Description page of Project Settings.

#include "OnTheRun.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GunAimingComponent.h"
class AGunActor;

// Sets default values for this component's properties
UGunAimingComponent::UGunAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UGunAimingComponent::SetGunReference(AActor* GunToSet, USkeletalMeshComponent* GunSkeletalToSet)
{
	Gun = Cast<AGunActor>(GunToSet);
	GunSkeletalMeshComponent = GunSkeletalToSet;
}

// Called when the game starts
void UGunAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGunAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UGunAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed, AActor* Character)
{
	/*auto OurCharacterName = GetOwner()->GetName();
	auto GunLocation = Gun->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("GunAmimingComponent: %s aiming at %s from %s "), *OurCharacterName, *HitLocation.ToString(), *GunLocation.ToString());
	*/
	
	if (!Gun) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = GunSkeletalMeshComponent->GetSocketLocation(FName("Projectile"));
	CurrentCharacter = Character;
	// Calculate the OutLaunchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		Gun->LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
		
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();

		//UE_LOG(LogTemp, Warning, TEXT("Launch Speed: %f StartLocation: %s"), Gun->LaunchSpeed, *StartLocation.ToString());
		UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"), *AimDirection.ToString());
		MoveCharacterTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim Solution found"), Time);
		 
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No aim solve found"), Time);
	}
}

void UGunAimingComponent::MoveCharacterTowards(FVector AimDirection)
{
	// Work-out difference between current gun rotation and AimDirection and rotate the character
	auto GunRotation = Gun->GetActorForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - GunRotation;
	auto RawRotation = CurrentCharacter->GetActorRotation();
	auto newRotation = FRotator(0.f, AimAsRotator.Yaw , 0.f);
	CurrentCharacter->SetActorRotation(newRotation);
	

	// Move the 
}
