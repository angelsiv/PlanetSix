// Fill out your copyright notice in the Description page of Project Settings.


#include "MK1_Pistol.h"

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
	
}

// Called every frame
void AMK1_Pistol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

