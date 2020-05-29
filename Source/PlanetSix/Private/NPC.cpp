// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC.h"
#include"Engine.h"

// Sets default values
ANPC::ANPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Declaring Box Component 
	boxcomponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = boxcomponent;
	
	//Declare TextRender
	textrender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TEXTRENDER"));
	textrender->AttachToComponent(boxcomponent, FAttachmentTransformRules::KeepRelativeTransform);

	// Declaring Skeleton of Npc
	skeleton = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletonMesh"));
	skeleton->AttachToComponent(boxcomponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();

	//Set the visibility of the text Press F to Interact to true 
	textrender->SetVisibility(false);

	//Play an animtion on begin play for the NPC 
	skeleton->PlayAnimation(AnimIdle, true);
}


// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//Add rotation to the text NOT YET PERFECT	
	/*auto camera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	textrender->SetWorldRotation(camera->GetCameraRotation());
	textrender->AddLocalRotation(FRotator(0, 180, 0));*/


}


void ANPC::NotifyActorBeginOverlap(AActor* OtherActor) //on ActorOverlap with the third person character 
{
	

	//This is to Show The informations of the Quest in the Widget 

	//		if (SpecifiedQuestOFNPC) 
	//		{
	//			Character->WidgetQuestNPC->TextName->Text = SpecifiedQuestOFNPC->Questinfo.QuestName;
	//			Character->WidgetQuestNPC->TextDescription->Text = SpecifiedQuestOFNPC->Questinfo.QuestDescription;

	//			for (int32 i = 0; i < SpecifiedQuestOFNPC->Questinfo.objectives.Num(); i++)
	//			{
	//				Character->WidgetQuestNPC->TextObjectives->Text = SpecifiedQuestOFNPC->Questinfo.objectives[i].ObjectiveDescription;
	//			}

	

		
	
}


void ANPC::NotifyActorEndOverlap(AActor* OtherActor)
{
	
}
