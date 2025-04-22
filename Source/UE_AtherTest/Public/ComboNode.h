// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComboInput.h"
#include "Containers/Map.h"

/**
 *
 */
class UComboNode 
{

public:
	UComboNode();

private:
	FString ActionName;
	TMap<EComboInput, UComboNode *> InputMap;

public:
	void AddNavigation(EComboInput Input, UComboNode *NextNode);
	UComboNode *Navigate(EComboInput Input);
	FString GetActionName();
	UComboNode *SetAction(FString Name);
};
