// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AbilityItemAttributeSet.generated.h"

#define ITEM_ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUsesExhausted);

/**
 * 
 */
UCLASS()
class GAMEPLAYABILITYITEMS_API UAbilityItemAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UAbilityItemAttributeSet();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& newValue) override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ability Item")
	FGameplayAttributeData MaxUses;
	ITEM_ATTRIBUTE_ACCESSORS(UAbilityItemAttributeSet, MaxUses)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ability Item")
	FGameplayAttributeData Uses;
	ITEM_ATTRIBUTE_ACCESSORS(UAbilityItemAttributeSet, Uses)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ability Item")
	FGameplayAttributeData UseCooldown;
	ITEM_ATTRIBUTE_ACCESSORS(UAbilityItemAttributeSet, UseCooldown)

	/* Not an attribute, but shows up in attribute menus like gameplay effects. TODO: Fix that. */
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Attribute Events")
	FUsesExhausted UsesExhausted;

};
