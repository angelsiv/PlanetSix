// Fill out your copyright notice in the Description page of Project Settings.


#include "MK1_Pistol.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "PlanetSixCharacter.h"
#include "GameFramework/Controller.h"

// Sets default values
AMK1_Pistol::AMK1_Pistol()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void AMK1_Pistol::BeginPlay()
{
	Super::BeginPlay();
	RecoilRate = .1f;

	RecoilPitchTop = .25f;
	RecoilPitchBot = -1.25f;

	RecoilYawLeft = -1.f;
	RecoilYawRight = 1.f;

	CurrentAmmo = 12;
	TotalAmmo = 36;
}

void AMK1_Pistol::Fire() 
{
	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{
		FVector EyeLocation;
		FRotator EyeRotation;
		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

		FVector ShotDirection = EyeRotation.Vector();

		FVector TraceEnd = EyeLocation + (ShotDirection * 10000);

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(MyOwner);
		QueryParams.AddIgnoredActor(this);
		QueryParams.bTraceComplex = true;

		FHitResult Hit;
		if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, ECC_Visibility, QueryParams)) 
		{
			AActor* HitActor = Hit.GetActor();
			UGameplayStatics::ApplyPointDamage(HitActor, 1.0f, ShotDirection, Hit, MyOwner->GetInstigatorController(), this, DamageType);
		}

		DrawDebugLine(GetWorld(), EyeLocation, TraceEnd, FColor::White, false, 1.0f, 0, 1.0f);
		Recoil();
	}
}

// Called every frame
void AMK1_Pistol::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (isRecoiling)
	{
		//AddControllerPitchInput(FinalRecoilPitch);
		//AddControllerYawInput(FinalRecoilYaw);
	}
}

void AMK1_Pistol::Recoil()
{
	FinalRecoilPitch = RecoilRate * FMath::FRandRange(0.25f, -1.25f);
	FinalRecoilYaw = RecoilRate * FMath::FRandRange(1.0f, -1.0f);
	//GetWorldTimerManager().SetTimer(this, &AMK1_Pistol::StopRecoil, .05f, true);
	isRecoiling = true;
}

void AMK1_Pistol::StopRecoil()
{
	isRecoiling = false;
	//GetWorldTimerManager().ClearTimer(this, &AMK1_Pistol::StopRecoil);
}

void AMK1_Pistol::Reload() 
{
	if (TotalAmmo <= 0 || CurrentAmmo >= 12) 
	{
		return; 
	}

	if (TotalAmmo < (12 - CurrentAmmo)) 
	{
		CurrentAmmo = CurrentAmmo + TotalAmmo;
		TotalAmmo = 0;
	}

	else 
	{
		TotalAmmo = TotalAmmo - (12 - CurrentAmmo);
		CurrentAmmo = 12;
	}
}
