// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityTask_TraceTargetFromActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "AbilityItemLibrary.h"

UAbilityTask_TraceTargetFromActor* UAbilityTask_TraceTargetFromActor::WaitTraceTargetDataFromActor(UGameplayAbility* OwningAbility, FName TaskInstanceName, AActor* TargetingActor, FCollisionProfileName TraceProfile, float MaxRange, ETraceTargetType TraceType, bool DrawDebug, float DrawTime)
{
	UAbilityTask_TraceTargetFromActor* MyObj = NewAbilityTask<UAbilityTask_TraceTargetFromActor>(OwningAbility, TaskInstanceName);
	MyObj->TargetingActor = TargetingActor;
	MyObj->TraceProfile = TraceProfile;
	MyObj->MaxRange = MaxRange;
	MyObj->TraceType = TraceType;
	MyObj->DrawDebug = DrawDebug;
	MyObj->DrawTime = DrawTime;
	return MyObj;
}

void UAbilityTask_TraceTargetFromActor::Activate()
{
	if (!IsValid(TargetingActor))
	{
		Failed.Broadcast(nullptr);
		return;
	}


	TargetReceived.Broadcast(MakeTargetDataFromHitResults(PerformTrace()));

}


// Performs the trace from the user viewpoint and returns all hits
TArray<FHitResult> UAbilityTask_TraceTargetFromActor::PerformTrace()
{
	FVector ViewOrigin;
	FRotator ViewRotation;
	UAbilityItemLibrary::GetItemUserViewpoint(ViewOrigin, ViewRotation, TargetingActor);
	FVector ViewEnd = ViewOrigin + MaxRange * UKismetMathLibrary::GetForwardVector(ViewRotation);

	TArray<AActor*> IgnoredActors = { TargetingActor };

	EDrawDebugTrace::Type DrawType = DrawDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None;
	float SphereRadius = 10;


	TArray<FHitResult> Hits;
	FHitResult Hit;

	// Perform Trace based on Trace Type
	switch (TraceType)
	{
	case ETraceTargetType::Trace_Line_Single: 
		UKismetSystemLibrary::LineTraceSingleByProfile(TargetingActor->GetWorld(), ViewOrigin, ViewEnd, TraceProfile.Name, false, IgnoredActors, DrawType, Hit, true, FLinearColor::Red, FLinearColor::Green, DrawTime);
		Hits.Add(Hit);
		break;
	case ETraceTargetType::Trace_Sphere_Single: 
		UKismetSystemLibrary::SphereTraceSingleByProfile(TargetingActor->GetWorld(), ViewOrigin, ViewEnd, SphereRadius, TraceProfile.Name, false, IgnoredActors, DrawType, Hit, true, FLinearColor::Red, FLinearColor::Green, DrawTime);
		Hits.Add(Hit);
		break;
	case ETraceTargetType::Trace_Line_Multi: 
		UKismetSystemLibrary::LineTraceMultiByProfile(TargetingActor->GetWorld(), ViewOrigin, ViewEnd, TraceProfile.Name, false, IgnoredActors, DrawType, Hits, true, FLinearColor::Red, FLinearColor::Green, DrawTime);
		break;
	case ETraceTargetType::Trace_Sphere_Multi: 
		UKismetSystemLibrary::SphereTraceMultiByProfile(TargetingActor->GetWorld(), ViewOrigin, ViewEnd, SphereRadius, TraceProfile.Name, false, IgnoredActors, DrawType, Hits, true, FLinearColor::Red, FLinearColor::Green, DrawTime);
		break;
	case ETraceTargetType::Trace_Custom: 
		break;
	default:
		break;
	}

	return Hits;
}

FGameplayAbilityTargetDataHandle UAbilityTask_TraceTargetFromActor::MakeTargetDataFromHitResults(TArray<FHitResult> HitResults)
{
	FGameplayAbilityTargetDataHandle ReturnHandle;

	for (const FHitResult HitResult : HitResults)
	{
		/* Uses target data structs provided by gameplay abilities plugin */
		FGameplayAbilityTargetData_SingleTargetHit* TargetData = new FGameplayAbilityTargetData_SingleTargetHit();
		TargetData->HitResult = HitResult;
		ReturnHandle.Add(TargetData);
	}

	return ReturnHandle;
}
