// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributesComponent.generated.h"

/** Base Attributes for all characters. */
UENUM(BlueprintType)
enum class EAttributes : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Brawn = 1 UMETA(DisplayName = "Brawn"),
	Vitality = 2 UMETA(DisplayName = "Vitality"),
	Agility = 4 UMETA(DisplayName = "Agility"),
	Mind = 8 UMETA(DisplayName = "Mind"),
	Social = 16 UMETA(DisplayName = "Social"),
	Fate = 32 UMETA(DisplayName = "Fate")
};

/** Base resistances for all characters. */
UENUM(BlueprintType)
enum class EResistances : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Physical_Resist = 1 UMETA(DisplayName = "Physical_Resist"),
	Energy_Resist = 2 UMETA(DisplayName = "Energy_Resist"),
	Fire_Resist = 4 UMETA(DisplayName = "Fire_Resist"),
	Ice_Resist = 8 UMETA(DisplayName = "Ice_Resist"),
	Electric_Resist = 16 UMETA(DisplayName = "Electric_Resist"),
	Corrosive_Resist = 32 UMETA(DisplayName = "Corrosive_Resist")
};

/** Base attributes for all characters in game. */
USTRUCT(BlueprintType)
struct PLANETSIX_API FAttributesData
{
	GENERATED_USTRUCT_BODY()

		FAttributesData()
		: BaseValue(0.f)
		, CurrentValue(0.f)
	{}

	FAttributesData(float DefaultValue)
		: BaseValue(DefaultValue)
		, CurrentValue(DefaultValue)
	{}

	/** getter for basevalue */
	float GetBaseValue() const;

	/** setter for basevalue */
	virtual void SetBaseValue(float NewValue);

	/** getter for currentvalue */
	float GetCurrentValue() const;

	/** setter for currentvalue */
	virtual void SetCurrentValue(float NewValue);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
		float BaseValue;
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
		float CurrentValue;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PLANETSIX_API UAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAttributesComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** Brawn attribute for the character */
	UPROPERTY(BlueprintReadOnly, Category = "Main Attributes", ReplicatedUsing = OnRep_Brawn)
		FAttributesData Brawn;
	/** Vitality attribute for the character */
	UPROPERTY(BlueprintReadOnly, Category = "Main Attributes", ReplicatedUsing = OnRep_Vitality)
		FAttributesData Vitality;
	/** Agility attribute for the character */
	UPROPERTY(BlueprintReadOnly, Category = "Main Attributes", ReplicatedUsing = OnRep_Agility)
		FAttributesData Agility;
	/** Mind attribute for the character */
	UPROPERTY(BlueprintReadOnly, Category = "Main Attributes", ReplicatedUsing = OnRep_Mind)
		FAttributesData Mind;
	/** Social attribute for the character */
	UPROPERTY(BlueprintReadOnly, Category = "Main Attributes", ReplicatedUsing = OnRep_Social)
		FAttributesData Social;
	/** Fate attribute for the character */
	UPROPERTY(BlueprintReadOnly, Category = "Main Attributes", ReplicatedUsing = OnRep_Fate)
		FAttributesData Fate;

	/** CurrentHealth attribute for the character */
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_CurrentHealth)
		FAttributesData CurrentHealth;
	/** MaxHealth attribute for the character */
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth)
		FAttributesData MaxHealth;
	/** CurrentEnergy attribute for the character */
	UPROPERTY(BlueprintReadOnly, Category = "Energy", ReplicatedUsing = OnRep_CurrentEnergy)
		FAttributesData CurrentEnergy;
	/** MaxEnergy attribute for the character */
	UPROPERTY(BlueprintReadOnly, Category = "Energy", ReplicatedUsing = OnRep_MaxEnergy)
		FAttributesData MaxEnergy;
	/** CurrentShield attribute for the character */
	UPROPERTY(BlueprintReadOnly, Category = "Shield", ReplicatedUsing = OnRep_CurrentShield)
		FAttributesData CurrentShield;

	/** This region below is for replication on a server - client model only*/
#pragma region OnRep_Attributes
	UFUNCTION()
		virtual void OnRep_Brawn();
	UFUNCTION()
		virtual void OnRep_Vitality();
	UFUNCTION()
		virtual void OnRep_Agility();
	UFUNCTION()
		virtual void OnRep_Mind();
	UFUNCTION()
		virtual void OnRep_Social();
	UFUNCTION()
		virtual void OnRep_Fate();
	UFUNCTION()
		virtual void OnRep_CurrentHealth();
	UFUNCTION()
		virtual void OnRep_MaxHealth();
	UFUNCTION()
		virtual void OnRep_CurrentEnergy();
	UFUNCTION()
		virtual void OnRep_MaxEnergy();
	UFUNCTION()
		virtual void OnRep_CurrentShield();

#pragma endregion

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
