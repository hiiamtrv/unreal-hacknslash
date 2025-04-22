// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include <AIGameSubsystem.h>

AActor* AEnemyAIController::GetNearestWaypoint()
{
	TArray<AActor*> Waypoints = GetWorld()->GetSubsystem<UAIGameSubsystem>()->Waypoints;
	if (Waypoints.Num() <= 0) return nullptr;
	AActor* BestWp = nullptr;
	double BestSqrDist = -1;
	FVector MyPosition = GetOwner()->GetActorLocation();
	for (auto Wp : Waypoints) {
		double SqrDist = (Wp->GetActorLocation() - MyPosition).SquaredLength();
		if (BestSqrDist < 0 || BestSqrDist > SqrDist) {
			BestWp = Wp;
			BestSqrDist = SqrDist;
		}
	}
	return BestWp;
}

AActor* AEnemyAIController::GetNextWaypoint(AActor* CurrentWaypoint)
{
	TArray<AActor*> Waypoints = GetWorld()->GetSubsystem<UAIGameSubsystem>()->Waypoints;
	if (Waypoints.Num() <= 0) return nullptr;
	bool bSelectNext = false;
	for (auto Wp : Waypoints) {
		if (bSelectNext) return Wp;
		bSelectNext = Wp == CurrentWaypoint;
	}
	return Waypoints[0];
}

void AEnemyAIController::HandlePlayerSight(AActor* Actor, FAIStimulus Stimulus, const FName& KeyName)
{
	if (Stimulus.Type != UAISense::GetSenseID(UAISense_Sight::StaticClass())) return;

	AActor* Player = GetWorld()->GetFirstPlayerController();
	if (Player != Actor) return;
	if (Stimulus.WasSuccessfullySensed()) {
		Blackboard->SetValueAsObject(KeyName, Actor);
	}
	else {
		Blackboard->SetValueAsObject(KeyName, nullptr);
	}
}
