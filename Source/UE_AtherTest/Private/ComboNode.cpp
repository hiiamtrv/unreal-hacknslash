// Fill out your copyright notice in the Description page of Project Settings.

#include "ComboNode.h"

UComboNode::UComboNode()
{
    InputMap.Reset();
    ActionName = TEXT("NA");
}

void UComboNode::AddNavigation(const EComboInput Input, UComboNode *NextNode)
{
    UE_LOG(LogTemp, Warning, TEXT("Add navigation: %s -> %s"), *GetActionName(), *(NextNode->GetActionName()));
    InputMap.Add(Input, NextNode);
}

UComboNode* UComboNode::Navigate(const EComboInput Input)
{
    if (UComboNode** NextNode = InputMap.Find(Input)){
        UComboNode* Result = *NextNode;
		return Result;
	}

    return nullptr;
}

FString UComboNode::GetActionName()
{
    return ActionName;
}

UComboNode* UComboNode::SetAction(FString Name)
{
    this->ActionName = Name;
    return this;
}
