// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "ItemUse.h"
#include "CrystalUse.generated.h"

/**
 *
 */
UCLASS()
class PLANETSIX_API ACrystalUse : public AItemUse
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int  Armor UMETA(ExposeOnSpawn = "true");
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int  AbilityDamage UMETA(ExposeOnSpawn = "true");
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int  Health UMETA(ExposeOnSpawn = "true");
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int  WeaponDamage UMETA(ExposeOnSpawn = "true");
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int  Shield UMETA(ExposeOnSpawn = "true");

public:

    
        void Use(APlanetSixCharacter* player) override;

};
