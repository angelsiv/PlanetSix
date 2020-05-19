// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
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
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	FString UserName;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	int32 Level;

};
