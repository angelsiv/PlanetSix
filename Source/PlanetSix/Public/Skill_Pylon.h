// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Skill_Pylon.generated.h"

class UAttributesComponent;

UCLASS()
class PLANETSIX_API ASkill_Pylon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkill_Pylon();

protected:
	UPROPERTY(EditAnywhere)
		class UBoxComponent* TriggerBox;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
		class APawn* OwnerPawn;
	UPROPERTY(VisibleAnywhere)
		class APlanetSixCharacter* Parent;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//when enemy enters, he starts taking damage
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	//when enemy exits, stops taking damage
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	/** Inflicts @Damage against an @EnemyComponent, depending on @Player's component attributes */
	void InflictDamage(UAttributesComponent* EnemyComponent, UAttributesComponent* PlayerComponent);
};
