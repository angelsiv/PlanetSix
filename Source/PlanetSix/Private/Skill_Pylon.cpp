// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_Pylon.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "../PlanetSixCharacter.h"
#include "../AttributesComponent.h"

// Sets default values
ASkill_Pylon::ASkill_Pylon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	TriggerBox->SetupAttachment(Mesh);

	Caster = CreateDefaultSubobject<APlanetSixCharacter>(TEXT("Owner Player"));

	OwnerPawn = Cast<APawn>(GetOwner());
}

// Called when the game starts or when spawned
void ASkill_Pylon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASkill_Pylon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/** when enemy enters, he starts taking damage*/
void ASkill_Pylon::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OwnerPawn != nullptr && OwnerPawn->GetLocalRole() == ROLE_Authority)
	{
		//class UAttributesComponent* EnemyComponent;
		//class UAttributesComponent* PlayerComponent;
		//EnemyComponent = Cast<UAttributesComponent>(OtherActor);
		//PlayerComponent = Cast<UAttributesComponent>(GetOwner());
		//InflictDamage(EnemyComponent, PlayerComponent);
		//auto Caster = Cast<APlanetSixCharacter>(OtherActor);
		//auto Enemy = Cast<APlanetSixCharacter>(OtherActor);
	}
}

/** when enemy exits, stops taking damage*/
void ASkill_Pylon::NotifyActorEndOverlap(AActor* OtherActor)
{

}

void ASkill_Pylon::InflictDamage(UAttributesComponent* EnemyComponent, UAttributesComponent* PlayerComponent)
{
	float Damage = PlayerComponent->WeaponsProficiency.GetCurrentValue() * PlayerComponent->Level.GetCurrentValue();
}