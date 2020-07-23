// This work is the sole property of 2Pow6 Games.


#include "LoadingGameMode.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "PlanetSixGameInstance.h"

ALoadingGameMode::ALoadingGameMode()
{
	bUseSeamlessTravel = true;
}

void ALoadingGameMode::BeginPlay()
{
	auto GameInstance = Cast<UPlanetSixGameInstance>(GetGameInstance());
	GetLevelNameToLoad(GameInstance->LevelToLoad);

	if (UGameplayStatics::GetPlayerController(GetWorld(), 0)->HasAuthority() && !(GetWorld()->IsInSeamlessTravel()) && LevelToLoad != "")
	{
		if (GetWorld()->ServerTravel(LevelToLoad.ToString()))
		{
		}
		if (GetLocalRole() == ROLE_Authority)
		{
			UGameplayStatics::OpenLevel(GetWorld(), LevelToLoad, true, "?listen");
			//Multi-travel
		}
	}
}

void ALoadingGameMode::GetLevelNameToLoad(FName LevelName)
{
	LevelToLoad = LevelName;
}
