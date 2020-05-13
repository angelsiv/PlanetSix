// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


/**
 * 
 */

 enum GoalType 
{
 Kill,
 Gathering,
 TalkToNpc,

};


class PLANETSIX_API Goal : UObject
{


public:
	Goal();
	~Goal();


	int countNeeded;
	int countCurrent;
	bool Completed;
	GoalType goaltype;

	void Increment(int amount);
	

};








