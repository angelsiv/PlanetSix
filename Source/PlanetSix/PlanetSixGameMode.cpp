// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PlanetSixGameMode.h"
#include "PlanetSixCharacter.h"
#include "UObject/ConstructorHelpers.h"

APlanetSixGameMode::APlanetSixGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
		bUseSeamlessTravel = true;
	}
}
