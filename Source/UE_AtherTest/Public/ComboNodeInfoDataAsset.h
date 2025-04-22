#pragma once

#include "CoreMinimal.h"
#include "ComboInput.h"
#include "ComboNodeInfoDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FComboNodeInfo
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PrecedingId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EComboInput EnterInput;
};

UCLASS(BlueprintType)
class UE_ATHERTEST_API UComboNodeInfoDataAsset : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RootName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FString, FComboNodeInfo> Nodes;
};
