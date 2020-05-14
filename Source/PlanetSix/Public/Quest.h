// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Quest.generated.h"



 enum ObjectiveType 
{
	 Kill,
	 Gathering,
	 TalkToNpc,

};


UCLASS()
class PLANETSIX_API UQuest : public UObject
{
	GENERATED_BODY()
	

public:

	//this is the name of the quest 
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category ="Quest")
	FText title;

	//this is the description of the quest 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FText Description;

	//check if the quest is active 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	bool isActive;

	//Rewards for when the lpayer finishes the quest 
	int ExperiecnceReward;



};

//this class represents the objectives the players needs to complete to succeed the quest 
class Objective
{

private:
	//ID for the quest 
	int id;

	//Define the type of the objective(s)
	ObjectiveType TypeOfObjective;

	//name of the objective 
	FText name;

	//Description of objective 
	FText description;

};
