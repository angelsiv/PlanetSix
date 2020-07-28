// This work is the sole property of 2Pow6 Games.


#include "ItemUse.h"

#define PRINT(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::Black,text)


// Sets default values
AItemUse::AItemUse()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemUse::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemUse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemUse::Use(APlanetSixCharacter* player)
{
	PRINT("no use", 1);
}

