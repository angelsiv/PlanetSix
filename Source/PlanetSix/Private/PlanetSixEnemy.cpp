// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetSixEnemy.h"
#include "WeaponComponent.h"
#include "PlanetSixCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "PlanetSixGameInstance.h"
#include "Engine/StaticMesh.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "Blueprint/UserWidget.h"

#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)

// Sets default values
APlanetSixEnemy::APlanetSixEnemy(const FObjectInitializer& ObjectInitializer)
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	MovComp = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovComp"));
	Attributes = CreateDefaultSubobject<UAttributesComponent>(TEXT("Attributes"));



	/*Mesh->SetGenerateOverlapEvents(false);
	Mesh->SetCollisionProfileName(TEXT("NoCollision"));
	Mesh->CanCharacterStepUpOn = ECB_No;

	Collider->SetGenerateOverlapEvents(true);
	Collider->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	Collider->CanCharacterStepUpOn = ECB_No;
	Collider->SetNotifyRigidBodyCollision(true);*/

	//AIControllerClass = AEnemyController::StaticClass();


	//RootComponent = Collider;
	//Collider->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1,ECollisionResponse::ECR_Block);

	SetReplicates(true);
}

// Called when the game starts or when spawned
void APlanetSixEnemy::BeginPlay()
{
	Super::BeginPlay();
	//Find Player
	NameWidget = CreateWidget<UUserWidget>(this, NameWidgetClass);
	EnemyMaterial = GetMesh()->CreateDynamicMaterialInstance(0, EnemyMaterial);
}

// Called every frame
void APlanetSixEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator WidgetRotation;

	FVector CameraLocation = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation();

	WidgetRotation = UKismetMathLibrary::FindLookAtRotation(Cast<USceneComponent>(NameWidget)->GetComponentLocation(), CameraLocation);

	Cast<USceneComponent>(NameWidget)->SetWorldRotation(WidgetRotation);
}

// Called to bind functionality to input
void APlanetSixEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

//bool APlanetSixEnemy::IsDead(float damage) {
//
//	return Info.bIsDead;
//
//}

void APlanetSixEnemy::Death()
{
	//Destroy();
	//add xp to the player
	auto OwnerPlayer = Cast<APlanetSixCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	OwnerPlayer->Attributes->GainExperience(Experience);
	//To check if Quest has a Killing condition
	UPlanetSixGameInstance* GameInstance = Cast<UPlanetSixGameInstance>(GetGameInstance());
	int objectiveNumber = GameInstance->GetCurrentQuest().AtObjectiveNumber;
	FQuestData CurrentQuest = GameInstance->GetCurrentQuest();
	if (CurrentQuest.objectives.Num() > 0) {
		//If at location
		if (CurrentQuest.objectives[objectiveNumber].LocationToGo == UGameplayStatics::GetCurrentLevelName(GetWorld())) {

			//If needs to kill
			if (CurrentQuest.objectives[objectiveNumber].Objectivetype == EObjectiveType::Kill)
			{
				print("Applying killing quest", -1);
					GameInstance->ReduceCurrentTargetNumber(GetID());
				
			}
		}
	}


}

int APlanetSixEnemy::GetID()
{
	return ID;
}

//void APlanetSixEnemy::GiveExperience(TArray<APlanetSixCharacter*> Players, float Exp)
//{
//	for (int i = 0; i < Players.Max(); i++)
//	{
//		Players[i]->Attributes->Experience.SetCurrentValue(Players[i]->Attributes->Experience.GetCurrentValue() + Experience);
//	}
//}