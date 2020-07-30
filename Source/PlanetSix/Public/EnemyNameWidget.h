// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlanetSixEnemy.h" 
#include "EnemyNameWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLANETSIX_API UEnemyNameWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	

	UPROPERTY(BlueprintReadWrite)
	FString Name UMETA(ExposeOnSpawn = "true");

	UPROPERTY(BlueprintReadWrite)
	APlanetSixEnemy* OwnerEnemy UMETA(ExposeOnSpawn = "true");

	UPROPERTY(BlueprintReadWrite)
	bool bIsVariablesInitialized;



};
