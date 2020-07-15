// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PlanetSixCharacter.h"
#include "Skill.h"
#include "PlanetSixSaveGame.generated.h"


/**
 * 
 */

USTRUCT(BlueprintType)
struct PLANETSIX_API FPlayerSaveData
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		FString SaveName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		TArray<int> QuestsRegistered;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		FString LastQuestRegisteredName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		TMap<int, int> InventoryItemsID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		TArray<FText> EquippedSkills;
	
	//ArmorProf 0,WeaponProf 1,AbilitiesProf 2,Level 3,Experience 4,Health 5,Shield 6,ArmorReduction 7,WeaponDamage 8,AbilityDamage 9

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		TArray<float> Attributes;

};



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
	
	//PlayerCharacter values
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FPlayerSaveData PlayerInfo;
};
