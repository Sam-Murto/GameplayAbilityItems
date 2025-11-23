// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityItemLibrary.h"
#include "AbilityItemUserInterface.h"

void UAbilityItemLibrary::GetItemUserViewpoint(FVector& OutLocation, FRotator& OutRotation, AActor* Actor)
{

	if (Actor->Implements<UAbilityItemUserInterface>())
	{
		Cast<IAbilityItemUserInterface>(Actor)->Execute_GetItemUserViewpoint(Actor, OutLocation, OutRotation);
		return;
	}

	// Default to regular viewpoint function when not implemented
	Actor->GetActorEyesViewPoint(OutLocation, OutRotation);

}
