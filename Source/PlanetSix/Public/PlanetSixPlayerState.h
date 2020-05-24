// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlanetSixPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PLANETSIX_API APlanetSixPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	//Player Stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString UserName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Level;
};
