// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NPCDialogueWidget.generated.h"

class ANPC;
/**
 * 
 */


UCLASS()
class PLANETSIX_API UNPCDialogueWidget : public UUserWidget
{
	GENERATED_BODY()

public: 

	UPROPERTY(BlueprintReadWrite)
		ANPC* NPC;
	
};
