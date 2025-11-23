// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AbilityItemLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYABILITYITEMS_API UAbilityItemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	 
public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="AbilityItemLibrary")
	static void GetItemUserViewpoint(FVector& OutLocation, FRotator& OutRotation, AActor* Actor);

};
