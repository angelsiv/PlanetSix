// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GoalQuest.generated.h"

/**
 * 
 */

enum GoalType
{
    Kill,
    Gathering,
    TalkToNpc,

};

UCLASS()
class PLANETSIX_API UGoalQuest : public UObject
{
	GENERATED_BODY()

public:
    int countNeeded;
    int countCurrent;
    bool Completed;
    GoalType goaltype;

    void Increment(int amount);

	
};
