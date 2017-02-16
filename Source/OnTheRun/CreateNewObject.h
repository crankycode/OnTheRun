// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "CreateNewObject.generated.h"

/**
 * 
 */
UCLASS()
class ONTHERUN_API UCreateNewObject : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintPure, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DisplayName = "Create Object From Blueprint", CompactNodeTitle = "Create", Keywords = "new create blueprint"), Category = Game)
	static AActor* NewObjectFromBlueprint(AActor* WorldContextObject, UClass* UC);

	
};
