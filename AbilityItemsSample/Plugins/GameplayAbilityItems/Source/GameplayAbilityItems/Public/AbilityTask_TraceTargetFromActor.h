// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_TraceTargetFromActor.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTargetTraceDelegate, const FGameplayAbilityTargetDataHandle&, Data);


UENUM()
enum ETraceTargetType : uint8
{
	Trace_Line_Single,
	Trace_Sphere_Single,
	Trace_Line_Multi,
	Trace_Sphere_Multi,
	Trace_Custom,
};

UCLASS()
class GAMEPLAYABILITYITEMS_API UAbilityTask_TraceTargetFromActor : public UAbilityTask
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintAssignable)
	FTargetTraceDelegate TargetReceived;

	UPROPERTY(BlueprintAssignable)
	FTargetTraceDelegate Failed;

	UFUNCTION(BlueprintCallable, Category = "AbilityItem|Ability", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly="TRUE", AdvancedDisplay = "TraceType,DrawDebug,DrawTime"))
	static UAbilityTask_TraceTargetFromActor* WaitTraceTargetDataFromActor
	(UGameplayAbility* OwningAbility, FName TaskInstanceName
	, AActor* TargetingActor, FCollisionProfileName TraceProfile, float MaxRange = 500
	, ETraceTargetType TraceType=ETraceTargetType::Trace_Line_Single, bool DrawDebug=false, float DrawTime=5.0f
	);

	virtual void Activate() override;

protected:

	/* Performs the trace and returns all hits. Can be overriden to use custom trace types */
	virtual TArray<FHitResult> PerformTrace();

	virtual FGameplayAbilityTargetDataHandle MakeTargetDataFromHitResults(TArray<FHitResult> HitResults);

protected:

	/* Properties for use in trace */
	TObjectPtr<AActor> TargetingActor;
	FCollisionProfileName TraceProfile;
	float MaxRange;
	ETraceTargetType TraceType;
	bool DrawDebug;
	float DrawTime;

};
