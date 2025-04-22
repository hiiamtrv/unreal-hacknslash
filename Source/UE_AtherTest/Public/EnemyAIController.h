// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISense_Sight.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class UE_ATHERTEST_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	AActor* GetNearestWaypoint();

	UFUNCTION(BlueprintCallable)
	AActor* GetNextWaypoint(AActor* CurrentWaypoint);

	UFUNCTION(BlueprintCallable)
	void HandlePlayerSight(AActor* Actor, FAIStimulus Stimulus, const FName& KeyName);
};
