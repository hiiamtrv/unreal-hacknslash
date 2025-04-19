// Fill out your copyright notice in the Description page of Project Settings.

#include "ComboSubsystem.h"

TMap<FString, UComboNode *> UComboSubsystem::RootNodes;

void UComboSubsystem::BuildTree(FString RootName, TMap<FString, FComboNodeInfo> ComboNodeInfo)
{
    TMap<FString, UComboNode *> InputMap;
    TMultiMap<FString, FString> PrecedingIds;
    InputMap[""] = new UComboNode(FString());

    for (auto KeyVal : ComboNodeInfo)
    {
        // Block empty ids to avoid overlapping with root
        if (KeyVal.Key == "")
            continue;
        InputMap[KeyVal.Key] = new UComboNode(KeyVal.Key);
        PrecedingIds.Add(KeyVal.Value.PrecedingId, KeyVal.Key);
    }

    for (auto KeyVal : PrecedingIds)
    {
        UComboNode *PNode = InputMap[KeyVal.Key];
        UComboNode *CNode = InputMap[KeyVal.Value];
        EComboInput Input = ComboNodeInfo[KeyVal.Value].ComboInput;
        PNode->AddNavigation(Input, CNode);
    }

    RootNodes.Add(RootName, InputMap[""]);
}

void UComboSubsystem::LoadCombo(FString RootName, TMap<FString, FComboNodeInfo> ComboNodeInfo)
{
    if (RootNodes.Contains(RootName))
        return;
    BuildTree(RootName, ComboNodeInfo);
}

UComboNode *UComboSubsystem::GetRootNode(FString RootName)
{
    if (RootNodes.Contains(RootName))
        return RootNodes[RootName];
    return nullptr;
}
