// This work is the sole property of 2Pow6 Games.


#include "WeaponBase.h"
#include "PlanetSixCharacter.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
	OwnerPlayer = Cast<APlanetSixCharacter>(GetOwner());
}

void AWeaponBase::Fire()
{
}

void AWeaponBase::Reload()
{
	// check if owner player has enough ammo in his bag
	OwnerPlayer->WeaponComponent->GetPrimaryAmmo().CurrentAmmo;
}

void AWeaponBase::Recoil()
{
}

void AWeaponBase::StopRecoil()
{
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

