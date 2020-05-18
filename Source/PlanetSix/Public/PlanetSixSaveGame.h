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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int32 UserIndex;
	
	//Player Character values
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FString UserName;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int32 Level;
};
