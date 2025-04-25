// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_AtherTestGameMode.h"
#include "UE_AtherTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_AtherTestGameMode::AUE_AtherTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
