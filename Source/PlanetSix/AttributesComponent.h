// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributesComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLANETSIX_API UAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttributesComponent();

	TMap<EAttributes, uint32> Attributes;
	TMap<EResistances, int32> Resistances;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};

/** Base Attributes for all characters. */
UENUM(BlueprintType)
enum class EAttributes : uint8
{
	Brawn UMETA(DisplayName = "Brawn"),
	Vitality UMETA(DisplayName = "Vitality"),
	Agility UMETA(DisplayName = "Agility"),
	Mind UMETA(DisplayName = "Mind"),
	Social UMETA(DisplayName = "Social"),
	Fate UMETA(DisplayName = "Fate")
};

UENUM(BlueprintType)
enum class EResistances : uint8
{
	Physical_Resist UMETA(DisplayName = "Physical_Resist"),
	Energy_Resist UMETA(DisplayName = "Energy_Resist"),
	Fire_Resist UMETA(DisplayName = "Fire_Resist"),
	Ice_Resist UMETA(DisplayName = "Ice_Resist"),
	Electric_Resist UMETA(DisplayName = "Electric_Resist"),
	Corrosive_Resist UMETA(DisplayName = "Corrosive_Resist")
};