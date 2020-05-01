// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PlanetSix\PlanetSixCharacter.h"
#include "Engine.h"
#include "Perception/AISenseConfig_Sight.h"
#include "EnemyController.generated.h"

/**
 * 
 */
#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)

 /**
  *
  */



UCLASS()
class PLANETSIX_API AEnemyController : public AAIController
{
	GENERATED_BODY()

public:

    AEnemyController();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Senses)
        UAIPerceptionComponent* PerceptionComp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Senses)
        UAISenseConfig_Sight* SightConfig;


protected:

    //Reference of all players in scene
    TArray<APlanetSixCharacter*> Players;

public:
    
    virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = Sight)
    void SenseStuff(const TArray<AActor*> &actors);


};

