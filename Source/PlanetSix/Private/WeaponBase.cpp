// This work is the sole property of 2Pow6 Games.


#include "WeaponBase.h"
#include "PlanetSixCharacter.h"
#include "Engine.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SKMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = SKMeshComponent;
	MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	MuzzleLocation->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	OwnerPlayer = Cast<APlanetSixCharacter>(GetOwner());
}

void AWeaponBase::Fire()
{
	//logic of firing : can't fire if jammed
	if (bIsWeaponJammed == false)
	{
		FVector StartFiringLocation;
		FVector EndFiringLocation;
		StartFiringLocation = MuzzleLocation->GetComponentLocation();
		EndFiringLocation = OwnerPlayer->CameraCrosshair;
		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(OwnerPlayer);
		QueryParams.AddIgnoredActor(this);
		QueryParams.bTraceComplex = true;
		FHitResult Hit;
		if (GetWorld()->LineTraceSingleByChannel(Hit, StartFiringLocation, EndFiringLocation, ECC_Visibility, QueryParams))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Shot fired"));

			DrawDebugLine(GetWorld(), StartFiringLocation, Hit.Location, FColor::White, false, 1.0f, 0, 1.0f);
		}
	}

	//did the weapon jam ? (it should be a low percentage of chance)
	bIsWeaponJammed = IsWeaponJammed();
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

bool AWeaponBase::IsWeaponJammed()
{
	return false;
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
