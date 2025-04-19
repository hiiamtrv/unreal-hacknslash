// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ComboNodeInfo.h"
#include "ComboSubsystem.h"
#include "ComboComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UE_ATHERTEST_API UComboComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UComboComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
	FString ComboRootName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
	TMap<FString, FComboNodeInfo> ComboNodeInfo;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction *ThisTickFunction) override;
};
