// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityItemAttributeSet.h"
#include "GameplayEffectExtension.h"

UAbilityItemAttributeSet::UAbilityItemAttributeSet()
{
	InitMaxUses(0);
	InitUses(0);
	InitUseCooldown(0.1);

}

void UAbilityItemAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& newValue)
{

	// Clamp uses
	if (Attribute == GetUsesAttribute())
	{
		newValue = FMath::Clamp(newValue, 0, GetMaxUses());

	}


}

void UAbilityItemAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{

	if (Data.EvaluatedData.Attribute == GetUsesAttribute())
	{
		float RemainingUses = GetUses();

		if (RemainingUses == 0)
		{
			UsesExhausted.Broadcast();
		}

	}

}
