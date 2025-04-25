// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "ComboAnimDataAsset.h"
#include "ComboAnimationPlayer.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UE_ATHERTEST_API UComboAnimationPlayer : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UComboAnimationPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
	TSoftObjectPtr<UComboAnimDataAsset> MontageAsset;

	UFUNCTION(BlueprintCallable)
	void PushMontageByKey(FString Key);

	UFUNCTION(BlueprintCallable)
	void PlayNextMontageIfHave();

	UFUNCTION(BlueprintCallable)
	void DiscardPendingMontage();

	UFUNCTION(BlueprintCallable)
	bool HavePendingMontage();

private:
	UComboAnimDataAsset* RefMontageAsset;
	UAnimMontage* CurrentMontage;
	UAnimMontage* PendingMontage;
	UAnimInstance* AnimInstance;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
