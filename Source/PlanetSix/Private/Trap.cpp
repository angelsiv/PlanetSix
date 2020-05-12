// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap.h"
#include "Components/BoxComponent.h"
#include "../ClassComponent.h"
#include "../EnemyController.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATrap::ATrap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	TriggerBox->SetupAttachment(Mesh);

	OwnerPawn = Cast<APawn>(GetOwner());
	//Parent = //l'acteur qui nous a spawné

}

// Called when the game starts or when spawned
void ATrap::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void ATrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//trigger the trap
void ATrap::NotifyActorBeginOverlap(AActor* OtherActor)
{
	//check if on server.
	if (OwnerPawn != nullptr && OwnerPawn->GetLocalRole() == ROLE_Authority)
	{
		//if OtherActor is enemy
		auto enemy = Cast<AEnemyController>(OtherActor);
		if (enemy != nullptr)
		{
			//switch depending on the faction : 
			switch (Parent->GetClassName())
			{
			case EClassName::Uni_Comrade:
				//case 1 : unionist

				break;
			case EClassName::Van_Volontaire:
				//case 2 : vanguard

				break;
			case EClassName::Pir_Gunner:
				//case 3 : pirate

				break;
			}
		}
	}


	//if not on server, start the visuals (if server returns player can perform action)

		//start animation

		//start VFX (depending on the type of trap)

}

//for fire, refresh the "enflamed" condition with this -> on END, stop restarting the flame timer.
void ATrap::NotifyActorEndOverlap(AActor* OtherActor)
{

}