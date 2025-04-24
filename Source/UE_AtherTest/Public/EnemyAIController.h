// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISense_Hearing.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UE_ATHERTEST_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	AActor* GetNearestWaypoint(TArray<AActor*> Waypoints);

	UFUNCTION(BlueprintCallable)
	AActor* GetNextWaypoint(AActor* CurrentWaypoint, TArray<AActor*> Waypoints);

	UFUNCTION(BlueprintCallable)
	void HandlePlayerSight(AActor* Actor, FAIStimulus Stimulus, const FName& KeyName);

	UFUNCTION(BlueprintCallable)
	void HandlePlayerHearing(AActor* Actor, FAIStimulus Stimulus, const FName& KeyName);
};
