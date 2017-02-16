// Fill out your copyright notice in the Description page of Project Settings.

#include "OnTheRun.h"
#include "Engine.h"
#include "CreateNewObject.h"

AActor* UCreateNewObject::NewObjectFromBlueprint(AActor* WorldContextObject, UClass* UC)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	AActor* tempObject = NewObject<AActor>(UC);

	return tempObject;
}


