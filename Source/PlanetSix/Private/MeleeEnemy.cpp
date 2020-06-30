// This work is the sole property of 2Pow6 Games.


#include "MeleeEnemy.h"

AMeleeEnemy::AMeleeEnemy(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;


	Attributes = CreateDefaultSubobject<UAttributesComponent>(TEXT("Attributes"));
	SetReplicates(true);

}