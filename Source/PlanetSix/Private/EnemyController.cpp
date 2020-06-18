// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyController.h"
#include "PlanetSixEnemy.h"
#include "EnemyAnimInstance.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"

#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)

AEnemyController::AEnemyController()
{


	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
	PerceptionComp->OnPerceptionUpdated.AddDynamic(this, &AEnemyController::SenseStuff);
	SetPerceptionComponent(*PerceptionComp);

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight"));
	SightConfig->PeripheralVisionAngleDegrees = 20;
	SightConfig->SightRadius = 1500;
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
	
	AnimInstance = Cast<UEnemyAnimInstance>(Cast<APlanetSixEnemy>(InPawn)->GetMesh()->GetAnimInstance());
	
	
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

float CountdownToShoot = 0;

void AEnemyController::Tick(float DeltaTime)
{
	if (PlayerInSight) {
		float distance = FVector::Distance(PlayerInSight->GetActorLocation(), GetPawn()->GetActorLocation());
		if (distance > 1500) {
			PlayerInSight = nullptr;
		}
		//print("Distance " + FString::SanitizeFloat(distance), 3);

		if (!IsFollowingAPath()) {
			AnimInstance->bIsShooting = true;
			//print("Is gonna shoot", -1);

			if (CountdownToShoot < 3) {
				CountdownToShoot += DeltaTime;

			}
			else {
				CountdownToShoot = 0;
				Shoot();
				//print("Shoot", -1);
			}
		}




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
				AnimInstance->bIsShooting = false;
				PlayerInSight = Cast<APlanetSixCharacter>(actor);
				print("Moving to " + PlayerInSight->GetFName().ToString(), -1);

			}

		}
	}
	else {
	
		if (AnimInstance->bIsShooting) {
			
			FVector Begin = GetPawn()->GetActorLocation();
			FVector End = PlayerInSight->GetActorLocation();

			FRotator RotationToLook = UKismetMathLibrary::FindLookAtRotation(Begin, End);
			FRotator LerpedRotation = FMath::Lerp(GetPawn()->GetActorRotation(), RotationToLook, 0.2);
			GetPawn()->SetActorRotation(LerpedRotation);

		
		}
		
	}

}

void AEnemyController::Shoot()
{

	if (PlayerInSight) {
	
		FVector Begin = GetPawn()->GetActorLocation();
		Begin.Z += 40;
		FVector End = PlayerInSight->GetActorLocation();

		FCollisionQueryParams QueryParams;
		QueryParams.bTraceComplex = true;

	
		DrawDebugLine(GetWorld(), Begin, End, FColor::Orange,false,3);
		print("Shoot at " + End.ToString() + " from " + Begin.ToString() , -1);

		auto Enemy = Cast<APlanetSixEnemy>(GetPawn());


		PlayerInSight->ReceiveDamage(Enemy->WeaponDamage());
			
	}
}
