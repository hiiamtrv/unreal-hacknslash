// Fill out your copyright notice in the Description page of Project Settings.

#include "ComboRunner.h"

// Sets default values for this component's properties
UComboRunner::UComboRunner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UComboRunner::BeginPlay()
{
	Super::BeginPlay();
	// ...

	const UWorld *World = GetWorld();
	UComboNodeInfoDataAsset *Data = ComboAsset.LoadSynchronous();
	if (Data)
	{
		UComboSubsystem* System = World->GetSubsystem<UComboSubsystem>();
		System->LoadCombo(Data->RootName, Data->Nodes);
		RootNode = System->GetRootNode(Data->RootName);
	}
	else {
		RootNode = nullptr;
	}

	ComboAnimationPlayer = GetOwner()->GetComponentByClass<UComboAnimationPlayer>();
	CurrentNode = RootNode;
	bCanFastforward = false;
	bIsInComboWindow = false;
}

// Called every frame
void UComboRunner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UComboRunner::HasValidComboTree()
{
	return RootNode != nullptr;
}

bool UComboRunner::IsInComboWindow()
{
	return !IsExecutingCombo() || bIsInComboWindow;
}

bool UComboRunner::IsExecutingCombo()
{
	return CurrentNode != RootNode;
}

void UComboRunner::SendInput(EComboInput Input)
{
	if (HasValidComboTree() && IsInComboWindow()) {
		UComboNode* ResultNode = CurrentNode->Navigate(Input);
		if (ResultNode != nullptr) {
			if (ComboAnimationPlayer != nullptr)
			{
				ComboAnimationPlayer->PushMontageByKey(ResultNode->GetActionName());
			}
			NextNode = ResultNode;

			if (!IsExecutingCombo() || bCanFastforward) {
				bIsInComboWindow = true;
				CloseComboWindow();
			}
		}
	}		
}

void UComboRunner::SendInputIfMatchCurrentName(EComboInput Input, FString CurrentName)
{
	if (!HasValidComboTree()) return;
	if (CurrentNode->GetActionName().Equals(CurrentName)) {
		SendInput(Input);
	}
}

void UComboRunner::HaltCombo()
{
	if (!bIsInComboWindow && NextNode == nullptr) return;
	//fake a situation that player input nothing
	bIsInComboWindow = true;
	NextNode = nullptr;
	CloseComboWindow();
}

void UComboRunner::OpenComboWindow()
{
	if (bIsInComboWindow) return;

	UE_LOG(LogTemp, Warning, TEXT("OpenComboWindow"));
	if (CurrentNode == nullptr) return;

	bIsInComboWindow = true;
	NextNode = nullptr;
}

void UComboRunner::CloseComboWindow()
{
	if (!bIsInComboWindow) return;

	bIsInComboWindow = false;
	bCanFastforward = false;
	if (NextNode != nullptr) {
		CurrentNode = NextNode;
		if (ComboAnimationPlayer != nullptr)
		{
			ComboAnimationPlayer->PlayNextMontageIfHave();
		}
		UE_LOG(LogTemp, Warning, TEXT("CloseComboWindow: Next node %s"), *NextNode->GetActionName());
	}
	else {
		CurrentNode = RootNode;
		if (ComboAnimationPlayer != nullptr)
		{
			ComboAnimationPlayer->DiscardPendingMontage();
		}
		UE_LOG(LogTemp, Warning, TEXT("CloseComboWindow: Reset to root nodes"));
	}
	NextNode = nullptr;
}

void UComboRunner::OpenFastfoward()
{
	//bCanFastforward = true;
	//if (NextNode != nullptr) {
	//	CloseComboWindow();
	//}
}

FString UComboRunner::GetCurrentNodeName()
{
	if (CurrentNode == nullptr) {
		return FString("NA");
	}
	else {
		return CurrentNode->GetActionName();
	}
}
