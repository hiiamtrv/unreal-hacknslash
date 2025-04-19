#pragma once

#include "CoreMinimal.h"
#include "ComboInput.generated.h"

UENUM(BlueprintType)
enum class EComboInput : uint8
{
	None UMETA(DisplayName = "None"),
	LAttack UMETA(DisplayName = "Light Attack"),
	HAttack UMETA(DisplayName = "Heavy Attack"),
	Shield UMETA(DisplayName = "Shield")
};