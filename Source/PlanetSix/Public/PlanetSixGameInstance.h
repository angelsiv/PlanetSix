// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlanetSixCharacter.h"
#include "PlanetSixGameInstance.generated.h"

/**
 *
 */
UCLASS()
class PLANETSIX_API UPlanetSixGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:


	//PlayerCharacter values
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FPlayerInfo PlayerInfo;

public:

	void SetPlayerInfo(FPlayerInfo info);

	void ReloadNetwork();
};
