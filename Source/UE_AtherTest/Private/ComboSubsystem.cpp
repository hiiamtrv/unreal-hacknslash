// Fill out your copyright notice in the Description page of Project Settings.

#include "ComboSubsystem.h"

TMap<FString, UComboNode *> UComboSubsystem::RootNodes;

UComboSubsystem::UComboSubsystem() {
    RootNodes.Reset();
}

void UComboSubsystem::BuildTree(FString RootName, const TMap<FString, FComboNodeInfo> &ComboNodeInfo)
{
    TMap<FString, UComboNode *> Nodes;
    TMultiMap<FString, FString> PrecedingIds;
    Nodes.Add(TEXT(""), (new UComboNode())->SetAction(TEXT("")));

    for (auto KeyVal : ComboNodeInfo)
    {
        // Block empty ids to avoid overlapping with root
        if (KeyVal.Key == "")
            continue;
        Nodes.Add(KeyVal.Key, (new UComboNode())->SetAction(KeyVal.Key));
        PrecedingIds.Add(KeyVal.Value.PrecedingId, KeyVal.Key);
    }
    
    for (auto KeyVal : PrecedingIds)
    {
        UComboNode *PNode = Nodes[KeyVal.Key];
        UComboNode *CNode = Nodes[KeyVal.Value];
        EComboInput Input = ComboNodeInfo[KeyVal.Value].EnterInput;
        PNode->AddNavigation(Input, CNode);
    }

    RootNodes.Add(RootName, Nodes[TEXT("")]);
}

void UComboSubsystem::LoadCombo(FString RootName, const TMap<FString, FComboNodeInfo> &ComboNodeInfo)
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
