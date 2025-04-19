// Fill out your copyright notice in the Description page of Project Settings.

#include "ComboNode.h"

UComboNode::UComboNode()
{
    InputMap.Reset();
}

UComboNode::UComboNode(FString s) {
    ActionName = s;
}

UComboNode::~UComboNode()
{
}

void UComboNode::AddNavigation(const EComboInput Input, UComboNode *NextNode)
{
    InputMap.Add(Input, NextNode);
}

UComboNode *UComboNode::Navigate(const EComboInput Input)
{
    if (InputMap.Contains(Input))
        return InputMap[Input];
    return nullptr;
}

FString UComboNode::GetActionName()
{
    return ActionName;
}
