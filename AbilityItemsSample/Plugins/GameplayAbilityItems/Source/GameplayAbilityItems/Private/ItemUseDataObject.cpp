// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemUseDataObject.h"

USkeletalMeshComponent* UItemUseDataObject::GetFirstPersonSkeletalMesh() const
{
    return nullptr;
}

USkeletalMeshComponent* UItemUseDataObject::GetThirdPersonSkeletalMesh() const
{
    return nullptr;
}

FGameplayTagContainer UItemUseDataObject::GetUseTags() const
{
    return FGameplayTagContainer();
}

void UItemUseDataObject::MakeItemUseDataObject(UItemUseDataObject*& ReturnValue, USkeletalMeshComponent* FirstPersonMesh, USkeletalMeshComponent* ThirdPersonMesh, FGameplayTagContainer UseTags)
{
    ReturnValue = NewObject<UItemUseDataObject>();
    ReturnValue->FirstPersonSkeletalMesh = FirstPersonMesh;
    ReturnValue->ThirdPersonSkeletalMesh = ThirdPersonMesh;
    ReturnValue->UseTags = UseTags;
}
