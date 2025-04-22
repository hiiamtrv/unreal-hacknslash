// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ComboNodeInfoDataAsset.h"
#include "ComboSubsystem.h"
#include "ComboAnimationPlayer.h"
#include "ComboRunner.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UE_ATHERTEST_API UComboRunner : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UComboRunner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
	TSoftObjectPtr<UComboNodeInfoDataAsset> ComboAsset;

	UFUNCTION(BlueprintCallable)
	void OpenComboWindow();

	UFUNCTION(BlueprintCallable)
	void CloseComboWindow();

private:
	UComboAnimationPlayer* ComboAnimationPlayer;
	bool bIsInComboWindow;
	UComboNode* RootNode;
	UComboNode* CurrentNode;
	UComboNode* NextNode;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction *ThisTickFunction) override;

	bool IsInComboWindow();

	bool IsExecutingCombo();

	void SendInput(EComboInput Input);
};
