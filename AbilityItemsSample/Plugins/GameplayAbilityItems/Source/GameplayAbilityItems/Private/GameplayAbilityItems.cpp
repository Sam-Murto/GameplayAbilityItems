// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayAbilityItems.h"
#include "GameplayTags.h"
#include "Misc/Paths.h"

#define LOCTEXT_NAMESPACE "FGameplayAbilityItemsModule"

void FGameplayAbilityItemsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UGameplayTagsManager::Get().AddTagIniSearchPath(FPaths::ProjectPluginsDir() / TEXT("GameplayAbilityItems/Config/Tags"));

}

void FGameplayAbilityItemsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGameplayAbilityItemsModule, GameplayAbilityItems)