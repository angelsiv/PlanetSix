// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetSixGameInstance.h"
#include "PlanetSixPlayerState.h"

#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)


void UPlanetSixGameInstance::SetPlayerInfo(FPlayerInfo info)
{
	PlayerInfo = info;

	ReloadNetwork();
}

FPlayerInfo UPlanetSixGameInstance::GetPlayerInfo()
{
	return PlayerInfo;
}

void UPlanetSixGameInstance::AddQuest(FQuestData Quest)
{
	if (!PlayerInfo.QuestsRegistered.Contains(Quest)) {
		
		PlayerInfo.QuestsRegistered.Add(Quest);
		PlayerInfo.QuestsRegistered.Sort([](const FQuestData& a, const FQuestData& b) {return a.QuestID < b.QuestID; });
		ReloadNetwork();
	}
	else {
		print("Quest already registered", -1);
	}
}

void UPlanetSixGameInstance::ReloadNetwork()
{
	APlanetSixPlayerState* PlayerState = GetPrimaryPlayerController()->GetPlayerState<APlanetSixPlayerState>();
	PlayerState->ReloadPlayerInfo();

}
