// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "Engine.h"

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
	if (Players.Num() > 0) {
		print("Caught " + FString::FromInt(Players.Num()) + " Players", -1);
		MoveToActor(Players[0]);
	}
}



void AEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
