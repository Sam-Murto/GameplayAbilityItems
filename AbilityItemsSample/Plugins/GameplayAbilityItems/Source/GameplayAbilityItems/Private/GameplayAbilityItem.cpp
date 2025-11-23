// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilityItem.h"
#include "AbilitySystemComponent.h"
#include "AbilityItemAttributeSet.h"

FName ItemAbilitySystem_Name = FName("ItemAbilitySystemComponent");

// Sets default values
AGameplayAbilityItem::AGameplayAbilityItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemAbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(ItemAbilitySystem_Name);

}

// Called when the game starts or when spawned
void AGameplayAbilityItem::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(ItemAbilitySystemComponent))
	{
		AbilityItemAttributeSet = ItemAbilitySystemComponent->GetSet<UAbilityItemAttributeSet>();
	}
	
}

UAbilitySystemComponent* AGameplayAbilityItem::GetAbilitySystemComponent() const
{
	return ItemAbilitySystemComponent;
}

void AGameplayAbilityItem::GetItemViewPointInternal(FVector& OutLocation, FRotator& OutRotation) const
{
	OutLocation = GetActorLocation();
	OutRotation = GetActorRotation();
}

void AGameplayAbilityItem::GetItemViewPoint_Implementation(FVector& OutLocation, FRotator& OutRotation) const
{
	GetItemViewPointInternal(OutLocation, OutRotation);
}

void AGameplayAbilityItem::GetActorEyesViewPoint(FVector& OutLocation, FRotator& OutRotation) const
{
	GetItemViewPoint(OutLocation, OutRotation);
}

