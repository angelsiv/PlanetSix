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

	if (LevelToLoad != "")
	{
		//FLatentActionInfo LatentInfo;
		//UGameplayStatics::LoadStreamLevel(GetWorld(), LevelToLoad, false, false, LatentInfo);
		if (GetWorld()->ServerTravel(LevelToLoad.ToString()))
		{
			//Single travel
		}
		if (GetLocalRole() == ROLE_Authority)
		{
			UGameplayStatics::OpenLevel(GetWorld(), LevelToLoad, true, "?listen");
			//Multi-travel
		}
	}
	//auto StreamLevel = UGameplayStatics::GetStreamingLevel(GetWorld(), LevelToLoad);

	//if (StreamLevel->GetLoadedLevel())
	//{
	//	if (GetWorld()->ServerTravel(LevelToLoad.ToString()))
	//	{
	//	}
	//	if (GetLocalRole() == ROLE_Authority)
	//	{
	//		UGameplayStatics::OpenLevel(GetWorld(), LevelToLoad, true, "?listen");
	//		//Multi-travel
	//	}
	//}
}

void ALoadingGameMode::GetLevelNameToLoad(FName LevelName)
{
	LevelToLoad = LevelName;
}
