// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyController.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"

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
		print("Caught " + FString::FromInt(Players.Num()) + " players in scene", -1);
	}
}



void AEnemyController::Tick(float DeltaTime)
{
	if (PlayerInSight) {
		float distance = FVector::Distance(PlayerInSight->GetActorLocation(), GetPawn()->GetActorLocation());
		print("Distance " + FString::SanitizeFloat(distance), 3);
	}
	Super::Tick(DeltaTime);
}

void AEnemyController::SenseStuff(const TArray<AActor*>& actors)
{
	if (!PlayerInSight) {
		if (Players.Num() < 0) {
			return;
		}
		for (AActor* actor : actors) {
			if (Players.Contains(actor)) {
				MoveToActor(actor, 500);
				PlayerInSight = Cast<APlanetSixCharacter>(actor);
				print("Moving to " + PlayerInSight->GetFName().ToString(), -1);

			}

		}
	}

}