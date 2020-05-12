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
	Armors_Proficiency = 1 UMETA(DisplayName = "Armors Proficiency"),
	Weapons_Proficiency = 2 UMETA(DisplayName = "Weapons Proficiency"),
	Abilities_Proficiency = 4 UMETA(DisplayName = "Abilities Proficiency"),
};

/** Base attributes for all characters in game. */
USTRUCT(BlueprintType)
struct PLANETSIX_API FAttributesData
{
	GENERATED_USTRUCT_BODY()

		FAttributesData()
		: BaseValue(1.f)
		, CurrentValue(BaseValue)
	{}

	FAttributesData(float DefaultValue)
		: BaseValue(1.f)
		, CurrentValue(DefaultValue + BaseValue)
		, CurrentModifier((int32)CurrentValue / 2)
	{}

	/** getter for basevalue */
	float GetBaseValue() const;

	/** getter for currentvalue */
	float GetCurrentValue() const;

	/** setter for currentvalue */
	virtual void SetCurrentValue(float NewValue);

	/** getter for the modifier */
	int32 GetCurrentModifier() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
		float BaseValue = 1.f;
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
		float CurrentValue;
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
		int32 CurrentModifier;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PLANETSIX_API UAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAttributesComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** armor attribute for the character */
	UPROPERTY(VisibleAnywhere, Category = "Main Attributes", ReplicatedUsing = OnRep_ArmorsProficiency)
		FAttributesData ArmorsProficiency;
	/** weapons attribute for the character */
	UPROPERTY(VisibleAnywhere, Category = "Main Attributes", ReplicatedUsing = OnRep_WeaponsProficiency)
		FAttributesData WeaponsProficiency;
	/** abilities attribute for the character */
	UPROPERTY(VisibleAnywhere, Category = "Main Attributes", ReplicatedUsing = OnRep_AbilitiesProficiency)
		FAttributesData AbilitiesProficiency;
	//------------------------------------------------------------------------------------------------------
	/** Level of the character */
	UPROPERTY(VisibleAnywhere, Category = "Level", ReplicatedUsing = OnRep_Level)
		FAttributesData Level;
	/** Experience points for the character */
	UPROPERTY(VisibleAnywhere, Category = "Level", ReplicatedUsing = OnRep_Experience)
		FAttributesData Experience;
	/** CurrentHealth attribute for the character */
	UPROPERTY(VisibleAnywhere, Category = "Health", ReplicatedUsing = OnRep_CurrentHealth)
		FAttributesData CurrentHealth;
	/** MaxHealth attribute for the character */
	UPROPERTY(VisibleAnywhere, Category = "Health", ReplicatedUsing = OnRep_MaxHealth)
		FAttributesData MaxHealth;
	/** CurrentEnergy attribute for the character */
	UPROPERTY(VisibleAnywhere, Category = "Energy", ReplicatedUsing = OnRep_CurrentEnergy)
		FAttributesData CurrentEnergy;
	/** MaxEnergy attribute for the character */
	UPROPERTY(VisibleAnywhere, Category = "Energy", ReplicatedUsing = OnRep_MaxEnergy)
		FAttributesData MaxEnergy;
	/** CurrentShield attribute for the character */
	UPROPERTY(VisibleAnywhere, Category = "Shield", ReplicatedUsing = OnRep_CurrentShield)
		FAttributesData CurrentShield;
	/** CurrentShield attribute for the character */
	UPROPERTY(VisibleAnywhere, Category = "Shield", ReplicatedUsing = OnRep_MaxShield)
		FAttributesData MaxShield;
	//------------------------------------------------------------------------------------------------------
	/** armor reduction attribute for the character */
	UPROPERTY(VisibleAnywhere, Category = "Armor", ReplicatedUsing = OnRep_ArmorReduction)
		FAttributesData ArmorReduction;
	/** weapon damage attribute for the character */
	UPROPERTY(VisibleAnywhere, Category = "Damage", ReplicatedUsing = OnRep_WeaponDamage)
		FAttributesData WeaponDamage;
	/** Ability damage attribute for the character */
	UPROPERTY(VisibleAnywhere, Category = "Damage", ReplicatedUsing = OnRep_AbilityDamage)
		FAttributesData AbilityDamage;

	/** Response to armors proficiency attribute being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnArmorsProficiencyUpdate();
	/** Response to weapons proficiency attribute being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnWeaponsProficiencyUpdate();
	/** Response to abilities proficiency attribute being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnAbilitiesProficiencyUpdate();
	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	/** Response to level being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnLevelUpdate();
	/** Response to experience being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnExperienceUpdate();
	/** Response to current health being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnCurrentHealthUpdate();
	/** Response to MAX health being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnMaxHealthUpdate();
	/** Response to current energy being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnCurrentEnergyUpdate();
	/** Response to MAX energy being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnMaxEnergyUpdate();
	/** Response to current shield being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnCurrentShieldUpdate();
	/** Response to MAX shield being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnMaxShieldUpdate();
	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	/** Response to armor reduction attribute being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnArmorReductionUpdate();
	/** Response to weapon damage attribute being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnWeaponDamageUpdate();
	/** Response to ability damage attribute being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnAbilityDamageUpdate();

	/** This region below is for replication on a server - client model only*/
#pragma region OnRep_Attributes
	UFUNCTION()
		virtual void OnRep_ArmorsProficiency();
	UFUNCTION()
		virtual void OnRep_WeaponsProficiency();
	UFUNCTION()
		virtual void OnRep_AbilitiesProficiency();
	//----------------------------------------------------
	UFUNCTION()
		virtual void OnRep_Level();
	UFUNCTION()
		virtual void OnRep_Experience();
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
	UFUNCTION()
		virtual void OnRep_MaxShield();
	//----------------------------------------------------
	UFUNCTION()
		virtual void OnRep_ArmorReduction();
	UFUNCTION()
		virtual void OnRep_WeaponDamage();
	UFUNCTION()
		virtual void OnRep_AbilityDamage();

#pragma endregion

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		class APawn* OwnerPawn;
};
