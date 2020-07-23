// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "LoadingGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PLANETSIX_API ALoadingGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ALoadingGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName LevelToLoad;

public:
	virtual void BeginPlay() override;
	void GetLevelNameToLoad(FName LevelName);
};
