// Fill out your copyright notice in the Description page of Project Settings.

#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "EnemyController.h"

AEnemyController::AEnemyController() 
{


	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
	PerceptionComp->OnPerceptionUpdated.AddDynamic(this, &AEnemyController::SenseStuff);
	SetPerceptionComponent(*PerceptionComp);

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight"));
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	PerceptionComp->SetDominantSense(SightConfig->GetSenseImplementation());
	PerceptionComp->ConfigureSense(*SightConfig);


}



void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	//SightConfig.
	//SightConfig->SightRadius = possessedUnit->sightRange;
	//SightConfig->LoseSightRadius = (possessedUnit->sightRange + 20.0f);
	//SightConfig->PeripheralVisionAngleDegrees = 360.0f;
	//SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	//SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	//SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	//PerceptionComp->ConfigureSense(*SightConfig);

}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
	TSubclassOf<APlanetSixCharacter> playerRef = APlanetSixCharacter::StaticClass();
	TArray<AActor*> result;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), playerRef, result);
	for (AActor* a : result) {
		Players.Add(Cast<APlanetSixCharacter>(a));
	}
	if (Players.Num() > 0) {
		print("Caught " + FString::FromInt(Players.Num()) + " Players", -1);
		//MoveToActor(Players[0]);
	}
}



void AEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyController::SenseStuff(const TArray<AActor*> &actors)
{
	print("Caught something", -1);
}