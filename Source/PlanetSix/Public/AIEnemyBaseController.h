// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PlanetSixEnemy.h"
#include "AIEnemyBaseController.generated.h"

/**
 * 
 */
UCLASS()
class PLANETSIX_API AAIEnemyBaseController : public AAIController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = Battle)
		APlanetSixCharacter* PlayerRef;

	UFUNCTION(BlueprintCallable)
	bool IsEnemyFollowingPath();

};
