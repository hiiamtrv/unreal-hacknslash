// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AIGameSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UE_ATHERTEST_API UAIGameSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	TArray<AActor*> Waypoints;
};
