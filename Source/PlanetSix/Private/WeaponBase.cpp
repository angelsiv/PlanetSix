// This work is the sole property of 2Pow6 Games.


#include "WeaponBase.h"
#include "PlanetSixCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "Engine.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SKMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = SKMeshComponent;
	MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	MuzzleLocation->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	AmmoType = EAmmoType::PrimaryAmmo;
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner() != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Owner is setup yes"));
		OwnerPlayer = Cast<APlanetSixCharacter>(GetOwner());
	}
}

void AWeaponBase::Fire_Implementation()
{
	//logic of firing : can't fire if jammed
	if (bIsWeaponJammed == false && AmmoInMagazine > 0)
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
			auto ActorHit = Cast<ABaseCharacter>(Hit.GetActor());
			if (ActorHit != nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Shot touched"));
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%f"), OwnerPlayer->WeaponDamage()));
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("LIFE OF ENEMY : %f"), ActorHit->Attributes->Health.GetCurrentValue()));
				ActorHit->ReceiveDamage(OwnerPlayer->WeaponDamage());
			}
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Shot fired"));
			OwnerPlayer->CameraCrosshair = OwnerPlayer->GetFollowCamera()->GetForwardVector();
			DrawDebugLine(GetWorld(), StartFiringLocation, Hit.Location, FColor::White, false, 1.0f, 0, 1.0f);
			DrawDebugLine(GetWorld(), StartFiringLocation, Hit.Location, FColor::Red, false, 1.0f, 0, 1.0f);
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
	if (OwnerPlayer->WeaponComponent->PrimaryAmmo.GetCurrentValue() <= 0 || AmmoInMagazine >= AmmoMaxInMagazine)
	{
		return;
	}
	//reload
	else
	{
		//if totalammo in reserves and in the magazine is less than the full size of a magazine, reload what's left of ammo.
		if (OwnerPlayer->WeaponComponent->PrimaryAmmo.GetCurrentValue() + AmmoInMagazine < AmmoMaxInMagazine)
		{
			AmmoInMagazine += OwnerPlayer->WeaponComponent->PrimaryAmmo.GetCurrentValue();
			OwnerPlayer->WeaponComponent->PrimaryAmmo.SetCurrentValue(0);
		}
		//normal reload
		else
		{
			OwnerPlayer->WeaponComponent->PrimaryAmmo.SetCurrentValue(OwnerPlayer->WeaponComponent->PrimaryAmmo.GetCurrentValue() - (AmmoMaxInMagazine - AmmoInMagazine));
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
