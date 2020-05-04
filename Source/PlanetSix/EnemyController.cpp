// Fill out your copyright notice in the Description page of Project Settings.

#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "EnemyController.h"

#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)

AEnemyController::AEnemyController()
{


	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
	PerceptionComp->OnPerceptionUpdated.AddDynamic(this, &AEnemyController::SenseStuff);
	SetPerceptionComponent(*PerceptionComp);

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight"));
	SightConfig->PeripheralVisionAngleDegrees = 20;
	SightConfig->SightRadius = 1000;
	SightConfig->LoseSightRadius = SightConfig->SightRadius + 20.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	PerceptionComp->SetDominantSense(SightConfig->GetSenseImplementation());
	PerceptionComp->ConfigureSense(*SightConfig);


}



void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
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
	if (Players.Num() < 0) {
		print("Caught " + FString::FromInt(Players.Num()) + " players in scene",-1);
	}
}



void AEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyController::SenseStuff(const TArray<AActor*>& actors)
{
	if (Players.Num() < 0) {
		return;
	}
	for (AActor* actor : actors) {
		if (Players.Contains(actor)) {
			MoveToActor(actor,20,true,true,false,0,true);
		}

	}




	print("Caught something", -1);
}