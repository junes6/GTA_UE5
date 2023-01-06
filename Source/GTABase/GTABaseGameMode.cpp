// Copyright Epic Games, Inc. All Rights Reserved.

#include "GTABaseGameMode.h"
#include "GTABaseCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGTABaseGameMode::AGTABaseGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
