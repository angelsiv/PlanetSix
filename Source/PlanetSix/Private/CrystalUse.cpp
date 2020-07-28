// This work is the sole property of 2Pow6 Games.


#include "CrystalUse.h"

#define PRINT(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::Black,text)


void ACrystalUse::Use(APlanetSixCharacter* player)
{
    //    int armorValue = Armor;
    //    int abilityValue = AbilityDamage;
    //    int healthValue = Health;
    //    int weaponValue = WeaponDamage;
    //    int shieldValue = Shield;
    //
    //    if (Equiped)
    //    {
    //        armorValue *= -1;
    //        abilityValue *= -1;
    //        healthValue *= -1;
    //        weaponValue *= -1;
    //        shieldValue *= -1;
    //    }
    //    player->Attributes->Health.BaseValue += healthValue;
    //    player->Attributes->AbilityDamage.BaseValue += abilityValue;
    //    player->Attributes->ArmorReduction.BaseValue += armorValue;
    //    player->Attributes->WeaponDamage.BaseValue += weaponValue;
    //    player->Attributes->Shield.BaseValue += shieldValue;
    //    Equiped = !Equiped;
    PRINT("use crystal", 1);
}
