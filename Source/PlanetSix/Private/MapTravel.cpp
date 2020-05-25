// Fill out your copyright notice in the Description page of Project Settings.


#include "MapTravel.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "PlanetSixCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)

// Sets default values
AMapTravel::AMapTravel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	LocationText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Location Name"));
	
	RootComponent = BoxCollider;
	MeshComponent->AttachToComponent(BoxCollider, FAttachmentTransformRules::KeepRelativeTransform);
	LocationText->AttachToComponent(BoxCollider, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AMapTravel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapTravel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMapTravel::TravelTo()
{
	if (!(GetWorld()->IsInSeamlessTravel()))
	{
		if (GetWorld()->ServerTravel(LevelName)) 
		{
			print("should travel", -1);	
		}
		else if (GetLocalRole() == ROLE_Authority)
		{
			UGameplayStatics::OpenLevel(GetWorld(), FName(*LevelName), true, "listen");
			print("single travel", -1);
		}
		else
		{
			print("not allowed to travel", -1);
		}
	}
}

