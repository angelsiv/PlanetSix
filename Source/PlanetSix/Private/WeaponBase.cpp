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
		APlayerCameraManager* CameraManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
		FVector StartFiringLocation;
		FVector EndFiringLocation;
		StartFiringLocation = MuzzleLocation->GetComponentLocation();
		EndFiringLocation = CameraManager->GetCameraLocation() + CameraManager->GetCameraRotation().Vector() * 10000;
		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(OwnerPlayer);
		QueryParams.AddIgnoredActor(this);
		QueryParams.bTraceComplex = true;
		FHitResult Hit;
		if (GetWorld()->LineTraceSingleByChannel(Hit, StartFiringLocation, EndFiringLocation, ECC_Visibility, QueryParams))
		{
			auto ActorHit = Cast<APlanetSixCharacter>(Hit.GetActor());
			if (ActorHit != nullptr)
			{
				ActorHit->ReceiveDamage(OwnerPlayer->WeaponDamage());
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Shot touched"));
			}
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Shot fired"));
			OwnerPlayer->CameraCrosshair = OwnerPlayer->GetFollowCamera()->GetForwardVector();
			DrawDebugLine(GetWorld(), StartFiringLocation, Hit.Location, FColor::White, false, 1.0f, 0, 1.0f);
			DrawDebugLine(GetWorld(), StartFiringLocation, EndFiringLocation, FColor::Red, false, 1.0f, 0, 1.0f);
		}
		AmmoInMagazine--;
		Recoil();
	}

	//did the weapon jam ? (it should be a low percentage of chance)
	bIsWeaponJammed = IsWeaponJammed();
}

void AWeaponBase::Reload()
{
	// check if owner player has enough ammo in his bag
	//if totalammo in reserves is empty OR magazine already full, don't reload
	if (OwnerPlayer->WeaponComponent->GetPrimaryAmmo() <= 0 || AmmoInMagazine >= AmmoMaxInMagazine)
	{
		return;
	}
	//reload
	else
	{
		//if totalammo in reserves and in the magazine is less than the full size of a magazine, reload what's left of ammo.
		if (OwnerPlayer->WeaponComponent->GetPrimaryAmmo() + AmmoInMagazine < AmmoMaxInMagazine)
		{
			AmmoInMagazine += OwnerPlayer->WeaponComponent->GetPrimaryAmmo();
			OwnerPlayer->WeaponComponent->SetPrimaryAmmo(0);
		}
		//normal reload
		else
		{
			OwnerPlayer->WeaponComponent->SetPrimaryAmmo(OwnerPlayer->WeaponComponent->GetPrimaryAmmo() - AmmoMaxInMagazine - AmmoInMagazine);
			AmmoInMagazine = AmmoMaxInMagazine;
		}
	}
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
