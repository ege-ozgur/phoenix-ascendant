// Copyright Epic Games, Inc. All Rights Reserved.

#include "PhoenixAscendantGameMode.h"
#include "PhoenixAscendantCharacter.h"
#include "UObject/ConstructorHelpers.h"

APhoenixAscendantGameMode::APhoenixAscendantGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
