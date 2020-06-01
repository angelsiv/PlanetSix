// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestActor.h"



#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)
// Sets default values
AQuestActor::AQuestActor()
{
	

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UDataTable> QuestActorDataObject(TEXT("DataTable'/Game/ThirdPersonCPP/Database/QuestDataTable.QuestDataTable'"));
	if (QuestActorDataObject.Succeeded()) 
	{
		QuestDatable = QuestActorDataObject.Object;
		
	}


}

void AQuestActor::OrganiseQuestInEditor()
{
	auto parentLocation = GetAttachParentActor()->GetActorLocation();
	SetActorLocation(parentLocation);

}

// Called when the game starts or when spawned
void AQuestActor::BeginPlay()
{
	Super::BeginPlay();
	
	

}



// Called every frame
void AQuestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

