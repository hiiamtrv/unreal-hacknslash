#pragma once

#include "CoreMinimal.h"
#include "ComboInput.h" 
#include "ComboNodeInfo.generated.h"

USTRUCT(BlueprintType)
struct FComboNodeInfo
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
    FString PrecedingId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
    EComboInput ComboInput;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
    FString ActionName;
};
