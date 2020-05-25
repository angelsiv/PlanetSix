// This work is the sole property of 2Pow6 Games.


#include "PlanetSixPlayerController.h"
#include "PlanetSixPlayerState.h"
#include "PlanetSixGameInstance.h"

#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)

void APlanetSixPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (PlayerState) {
		Cast<APlanetSixPlayerState>(PlayerState)->ChangeInfo(Cast<UPlanetSixGameInstance>(GetGameInstance())->PlayerInfo);
		print("Used Game instance for name  " + Cast<APlanetSixPlayerState>(PlayerState)->GetInfo().UserName, -1);
	}
	else {
		print("Failure", -1);
	}
}
