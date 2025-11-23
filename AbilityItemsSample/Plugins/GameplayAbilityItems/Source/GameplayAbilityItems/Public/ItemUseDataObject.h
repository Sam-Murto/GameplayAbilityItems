// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "ItemUseDataObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GAMEPLAYABILITYITEMS_API UItemUseDataObject : public UObject
{
	GENERATED_BODY()

public:

protected:

public:
	/* Skeletal Mesh Component of the item user. Use this mesh to play animation montages on the item user that will only be seen by the using player. */
	class USkeletalMeshComponent* FirstPersonSkeletalMesh;
	/* Skeletal Mesh Component of the item user. Use this mesh to play animation montages on the item user that will be seen by everyone. */
	class USkeletalMeshComponent* ThirdPersonSkeletalMesh;

	/* Used for tags that don't make sense to be "owned" but should still drive ability logic
	(e.g. Deciding which animation montage to use for use an item in the off hand vs main hand). */
	FGameplayTagContainer UseTags;

public:

	/* Returns the Skeletal Mesh Component of the item user. Use this mesh to play animation montages on the item user that will only be seen by the using player. */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual USkeletalMeshComponent* GetFirstPersonSkeletalMesh() const;

	/* Returns the Skeletal Mesh Component of the item user. Use this mesh to play animation montages on the item user that will be seen by everyone. */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual USkeletalMeshComponent* GetThirdPersonSkeletalMesh() const;

	/* Returns UseTags for this use of the item. Used for tags that don't make sense to be "owned" but should still drive ability logic
	(e.g. Deciding which animation montage to use for use an item in the off hand vs main hand). */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual FGameplayTagContainer GetUseTags() const;

	/* Makes an ItemUseDataObject. This is data meant to drive ability logic that is not provided by ActorInfo 
	(Instigator's meshes, logic driving tags). */
	UFUNCTION(BlueprintCallable)
	static void MakeItemUseDataObject(UItemUseDataObject*& ReturnValue, USkeletalMeshComponent* FirstPersonMesh, USkeletalMeshComponent* ThirdPersonMesh, FGameplayTagContainer UseTags);

};
