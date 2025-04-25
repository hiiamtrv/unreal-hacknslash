// Fill out your copyright notice in the Description page of Project Settings.

#include "ComboAnimationPlayer.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UComboAnimationPlayer::UComboAnimationPlayer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UComboAnimationPlayer::BeginPlay()
{
	Super::BeginPlay();

	// ...
	RefMontageAsset = MontageAsset.LoadSynchronous();
	PendingMontage = nullptr;

	ACharacter *Owner = Cast<ACharacter>(GetOwner());
	AnimInstance = Owner->GetMesh()->GetAnimInstance();
}

// Called every frame
void UComboAnimationPlayer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UComboAnimationPlayer::PushMontageByKey(FString Key)
{
	if (RefMontageAsset && RefMontageAsset->ComboMontages.Contains(Key))
	{
		PendingMontage = RefMontageAsset->ComboMontages[Key];
	}
}
void UComboAnimationPlayer::PlayNextMontageIfHave()
{
	if (PendingMontage == nullptr)
		return;

	AnimInstance->Montage_Play(PendingMontage);
	CurrentMontage = PendingMontage;
	PendingMontage = nullptr;
}

void UComboAnimationPlayer::DiscardPendingMontage()
{
	PendingMontage = nullptr;
}

bool UComboAnimationPlayer::HavePendingMontage()
{
	return PendingMontage != nullptr;
}
