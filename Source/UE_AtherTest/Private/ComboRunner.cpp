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

	ComboAnimationPlayer = GetOwner()->GetComponentByClass<UComboAnimationPlayer>();
	CurrentNode = RootNode;
}

// Called every frame
void UComboRunner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
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
	if (IsInComboWindow()) {
		UComboNode* ResultNode = CurrentNode->Navigate(Input);
		if (ResultNode != nullptr) {
			ComboAnimationPlayer->PushMontageByKey(ResultNode->GetActionName());
			NextNode = ResultNode;

			if (!IsExecutingCombo()) {
				CloseComboWindow();
			}
		}
	}		
}

void UComboRunner::OpenComboWindow()
{
	UE_LOG(LogTemp, Warning, TEXT("OpenComboWindow"));
	if (CurrentNode == nullptr) return;
	bIsInComboWindow = true;
}

void UComboRunner::CloseComboWindow()
{
	bIsInComboWindow = false;
	if (NextNode != nullptr) {
		CurrentNode = NextNode;
		ComboAnimationPlayer->PlayNextMontageIfHave();
		UE_LOG(LogTemp, Warning, TEXT("CloseComboWindow: Next node %s"), *NextNode->GetActionName());
	}
	else {
		CurrentNode = RootNode;
		UE_LOG(LogTemp, Warning, TEXT("CloseComboWindow: Reset to root nodes"));
	}
	NextNode = nullptr;
}
