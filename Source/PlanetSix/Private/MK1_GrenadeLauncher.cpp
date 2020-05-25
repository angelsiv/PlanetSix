// This work is the sole property of 2Pow6 Games.


#include "MK1_GrenadeLauncher.h"
#include "GrenadeLauncherProjectile.h"
#include "PlanetSixCharacter.h"
#include "Engine.h"

AMK1_GrenadeLauncher::AMK1_GrenadeLauncher()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	MuzzleLocation->SetupAttachment(RootComponent);
}

void AMK1_GrenadeLauncher::BeginPlay()
{
	Super::BeginPlay();

	WRLD = GetWorld();
}

void AMK1_GrenadeLauncher::Fire()
{
	if (GetOwner() != nullptr)
	{
		auto MyOwner = Cast<APlanetSixCharacter>(GetOwner());
		if (MyOwner)
		{
			const FRotator SpawnRotation = MuzzleLocation->GetComponentRotation();
			const FVector SpawnLocation = MuzzleLocation->GetComponentLocation();
			GEngine->AddOnScreenDebugMessage('c', 1.5, FColor::White, TEXT("trying to spawn projectile"));
			WRLD->SpawnActor(GrenadeProjectile, &SpawnLocation, &SpawnRotation);
			GEngine->AddOnScreenDebugMessage('c', 1.5, FColor::White, TEXT("Successfully spawned projectile"));
		}
	}
}


void AMK1_GrenadeLauncher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMK1_GrenadeLauncher::Reload()
{

}

