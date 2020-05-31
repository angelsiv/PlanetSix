// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetSixGameInstance.h"
#include "PlanetSixPlayerState.h"

void UPlanetSixGameInstance::SetPlayerInfo(FPlayerInfo info)
{
	PlayerInfo = info;
	
	
	
	ReloadNetwork();
}

void UPlanetSixGameInstance::ReloadNetwork()
{
	APlanetSixPlayerState* PlayerState = GetPrimaryPlayerController()->GetPlayerState<APlanetSixPlayerState>();
	PlayerState->ReloadPlayerInfo();

}
