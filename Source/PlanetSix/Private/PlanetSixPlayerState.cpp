// This work is the sole property of 2Pow6 Games.


#include "PlanetSixPlayerState.h"
#include "PlanetSixGameInstance.h"

#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)


void APlanetSixPlayerState::ChangeName_Implementation(const FString& name)
{

	UserName = name;
}



FString APlanetSixPlayerState::GetName()
{
	return UserName;
}


void APlanetSixPlayerState::CopyProperties(APlayerState* PlayerState)
{
	Super::CopyProperties(PlayerState);
	if (PlayerState) {
		APlanetSixPlayerState* MyPlayerState = Cast<APlanetSixPlayerState>(PlayerState);
		if (MyPlayerState)
			MyPlayerState->UserName = UserName;
	}



}

void APlanetSixPlayerState::OverrideWith(APlayerState* PlayerState)
{
	Super::OverrideWith(PlayerState);
	if (PlayerState) {
		APlanetSixPlayerState* MyPlayerState = Cast<APlanetSixPlayerState>(PlayerState);
		if (MyPlayerState)
			UserName = MyPlayerState->UserName;
	}

}

void APlanetSixPlayerState::BeginPlay()
{
	Super::BeginPlay();
	if (!HasAuthority()) {
		ChangeName(Cast<UPlanetSixGameInstance>(GetGameInstance())->UserName);
		//print("Used Game instance for name  " + Cast<UPlanetSixGameInstance>(GetGameInstance())->UserName, -1);
	}

}
