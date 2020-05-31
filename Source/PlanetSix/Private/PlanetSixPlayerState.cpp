// This work is the sole property of 2Pow6 Games.


#include "PlanetSixPlayerState.h"
#include "PlanetSixGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "PlanetSixSaveGame.h"
#include "Net/UnrealNetwork.h"

#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)


void APlanetSixPlayerState::ChangeInfo_Implementation(const FPlayerInfo& info)
{

	PlayerInfo = info;
}



FPlayerInfo APlanetSixPlayerState::GetInfo()
{
	return PlayerInfo;
}


void APlanetSixPlayerState::CopyProperties(APlayerState* PlayerState)
{
	Super::CopyProperties(PlayerState);
	if (PlayerState) {
		APlanetSixPlayerState* MyPlayerState = Cast<APlanetSixPlayerState>(PlayerState);
		if (MyPlayerState)
			MyPlayerState->PlayerInfo = PlayerInfo;
	}



}

void APlanetSixPlayerState::OverrideWith(APlayerState* PlayerState)
{
	Super::OverrideWith(PlayerState);
	if (PlayerState) {
		APlanetSixPlayerState* MyPlayerState = Cast<APlanetSixPlayerState>(PlayerState);
		if (MyPlayerState)
			PlayerInfo = MyPlayerState->PlayerInfo;
	}

}

void APlanetSixPlayerState::BeginPlay() {
	//If Inputed name doesnt exist
	Super::BeginPlay();
	/*USaveGame* SavedGame = UGameplayStatics::LoadGameFromSlot("Test", 0);
	if (SavedGame) {
		UPlanetSixSaveGame* PSavedGame = Cast<UPlanetSixSaveGame>(SavedGame);

		ChangeInfo(PSavedGame->PlayerInfo);
	}*/

	//if (!HasAuthority()) {
		ReloadPlayerInfo();
		print("Connecting to game instance with name: " + Cast<UPlanetSixGameInstance>(GetGameInstance())->PlayerInfo.UserName, -1);
	//}
}


void APlanetSixPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APlanetSixPlayerState, PlayerInfo);
}


void APlanetSixPlayerState::ReloadPlayerInfo() {

	ChangeInfo(Cast<UPlanetSixGameInstance>(GetGameInstance())->PlayerInfo);

}