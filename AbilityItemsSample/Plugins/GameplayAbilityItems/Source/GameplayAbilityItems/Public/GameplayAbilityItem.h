// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "GameplayAbilityItem.generated.h"

UCLASS()
class GAMEPLAYABILITYITEMS_API AGameplayAbilityItem : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameplayAbilityItem();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Item Abilities", meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* ItemAbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Abilities", meta = (AllowPrivateAccess = "true"))
	const class UAbilityItemAttributeSet* AbilityItemAttributeSet;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void GetItemViewPointInternal(FVector& Outlocation, FRotator& OutRotation) const;

public:	
	// The "Eyes" Viewpoint of the item. This is for handling targeting when an item is unowned (like if a gun goes off with no one holding it). If an Item Ability is used with no instigating actor then this viewpoint is used.
	UFUNCTION(BlueprintCallable, BlueprintPure, BlueprintNativeEvent, Category = "Ability Item")
	void GetItemViewPoint(FVector& OutLocation, FRotator& OutRotation) const;
	virtual void GetItemViewPoint_Implementation(FVector& OutLocation, FRotator& OutRotation) const;

	virtual void GetActorEyesViewPoint(FVector& OutLocation, FRotator& OutRotation) const override;


};
