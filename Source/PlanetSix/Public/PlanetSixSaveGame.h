// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PlanetSixSaveGame.generated.h"


/**
 * 
 */
UCLASS()
class PLANETSIX_API UPlanetSixSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	
	UPlanetSixSaveGame();

	//Reserved space for inventory stuff till Adrien fixes his stuff


	//

	UPROPERTY(VisibleAnywhere)
		FString SaveSlotName;

	UPROPERTY(VisibleAnywhere)
		uint32 UserIndex;
	
	//Player Character values
	UPROPERTY(VisibleAnywhere)
		FString UserName;
	UPROPERTY(VisibleAnywhere)
		uint32 Level;
};
