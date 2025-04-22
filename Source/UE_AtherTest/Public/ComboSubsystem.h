// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Containers/Map.h"
#include "ComboNodeInfoDataAsset.h"
#include "ComboNode.h"
#include "ComboSubsystem.generated.h"

/**
 *
 */
UCLASS()
class UE_ATHERTEST_API UComboSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UComboSubsystem();

private:
	static TMap<FString, UComboNode *> RootNodes;
	void BuildTree(FString RootName, const TMap<FString, FComboNodeInfo> &ComboNodeInfo);

public:
	void LoadCombo(FString RootName, const TMap<FString, FComboNodeInfo> &ComboNodeInfo);
	static UComboNode *GetRootNode(FString RootName);
};
