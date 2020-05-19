// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestActor.generated.h"

UCLASS()
class PLANETSIX_API AQuestActor : public AActor
{
	GENERATED_BODY()


public:	
	// Sets default values for this actor's properties
	AQuestActor();

	//this is the name of the quest 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
		FText QuestName;

	UFUNCTION(CallInEditor, BlueprintCallable)
		void OrganiseQuestInEditor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
