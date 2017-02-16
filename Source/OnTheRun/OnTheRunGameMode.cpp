// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "OnTheRun.h"
#include "OnTheRunGameMode.h"
#include "OnTheRunCharacter.h"

AOnTheRunGameMode::AOnTheRunGameMode()
{
	// set default pawn class to our Blueprinted character
	// static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Behaviour/MyCharacter"));
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Player/Behaviour/MyCharacter.MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
