// Fill out your copyright notice in the Description page of Project Settings.


#include "ClassComponent.h"

// Sets default values for this component's properties
UClassComponent::UClassComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	ClassEnumName = EClassName::Uni_Comrade;

	//SkillPylon = CreateDefaultSubobject<ASkill_Pylon>(TEXT("Pylon"));
}

// Called when the game starts
void UClassComponent::BeginPlay()
{
	Super::BeginPlay();

	FString TempDescription = TEXT("BLANK"); //TODO : implement a database to change that

	//depending on the class, let's add a description to it.
	ClassDescription = TempDescription;
}

// Called every frame
void UClassComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

EClassName UClassComponent::GetClassName()
{
	return ClassEnumName;
}

void UClassComponent::CastSkill(ESkill SkillName)
{

}