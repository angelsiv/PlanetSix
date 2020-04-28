// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseCharacter.generated.h"

UCLASS()
class PLANETSIX_API ABaseCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseCharacter();

	/** Base Attributes for all characters. */
	enum EAttributes 
	{ 
		Brawn = 1, 
		Vitality = 2, 
		Agility = 3, 
		Mind = 4, 
		Social = 5, 
		Fate = 6 
	};

	enum EResistances
	{
		Physical_Resist,
		Energy_Resist,
		Fire_Resist,
		Ice_Resist,
		Electric_Resist,
		Corrosive_Resist
	};

	TMap<EAttributes, uint32> Attributes;
	TMap<EResistances, uint32> Resistances;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
