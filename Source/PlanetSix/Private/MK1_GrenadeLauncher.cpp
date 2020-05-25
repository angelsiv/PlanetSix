// This work is the sole property of 2Pow6 Games.


#include "MK1_GrenadeLauncher.h"

AMK1_GrenadeLauncher::AMK1_GrenadeLauncher()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

void AMK1_GrenadeLauncher::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMK1_GrenadeLauncher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

