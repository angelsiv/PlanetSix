// This work is the sole property of 2Pow6 Games.


#include "MK1_GrenadeLauncher.h"
#include <GrenadeLauncherProjectile.h>
#include "Engine.h"

AMK1_GrenadeLauncher::AMK1_GrenadeLauncher()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("VR_MuzzleLocation"));
	MuzzleLocation->SetupAttachment(MeshComp);
}

void AMK1_GrenadeLauncher::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMK1_GrenadeLauncher::Fire() 
{
	AActor* MyOwner = GetOwner();
	if (MyOwner) 
	{
		const FRotator SpawnRotation = MuzzleLocation->GetComponentRotation();
		const FVector SpawnLocation = MuzzleLocation->GetComponentLocation();
		GetWorld()->SpawnActor <AGrenadeLauncherProjectile> (SpawnLocation, SpawnRotation);
	}
}


void AMK1_GrenadeLauncher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMK1_GrenadeLauncher::Reload()
{

}

