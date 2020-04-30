// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"
#include "Components/BoxComponent.h"
#include"Engine.h"


// Sets default values
ANPC::ANPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ScenecomponentRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	ScenecomponentRoot -> AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ScenecomponentRoot = RootComponent;

	//Declare Mesh Component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	MeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	//Declaring Box Component 
	boxcomponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	boxcomponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	boxcomponent->SetRelativeScale3D(FVector(6.0f));

	//Declare TextRender
	textrender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TEXTRENDER"));
	textrender->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);




}


// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();

	textrender->SetVisibility(false);

	
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
	auto character = Cast<APlanetSixCharacter>(OtherActor);
	 
	if (character != nullptr) {

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("Show me text"));
		//set visible the Text renderer of the NPC
		textrender->SetVisibility(true);
		
	}

}


void ANPC::NotifyActorEndOverlap(AActor* OtherActor)
{
	auto character = Cast<APlanetSixCharacter>(OtherActor);

	if (character != nullptr) {

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("bye bye text"));
		textrender->SetVisibility(false);

	}

}



