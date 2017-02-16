// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OnTheRunCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class ONTHERUN_API APatrollingGuard : public AOnTheRunCharacter
{
	GENERATED_BODY()
public:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPointsCPP;
	
	
};
