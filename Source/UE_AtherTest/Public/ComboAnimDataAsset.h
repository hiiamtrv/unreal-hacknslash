// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Animation/AnimMontage.h"
#include "Containers/Map.h"
#include "ComboAnimDataAsset.generated.h"

UCLASS()
class UE_ATHERTEST_API UComboAnimDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, UAnimMontage *> ComboMontages;
};
