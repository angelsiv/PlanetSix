// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"

#define print(text,i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)

Goal::Goal()
{

}

Goal::~Goal()
{

}


void Goal::Increment(int amount)
{

	if (countCurrent >= countNeeded && !Completed) 
	{
		fmin(countCurrent + 1, countNeeded);
		this->Completed = true;
		print("Goal Completed", 4);

	}
}
