// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlanetSixCharacter.h"
#include "GameFramework/Actor.h"
#include "Trap.generated.h"

UCLASS()
class PLANETSIX_API ATrap : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
		class UBoxComponent* TriggerBox;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
		class APawn* OwnerPawn;
	UPROPERTY(VisibleAnywhere)
		APlanetSixCharacter* Parent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//trigger the trap
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	//for fire, refresh the "enflamed" condition with this -> on END, stop restarting the flame timer.
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

};
