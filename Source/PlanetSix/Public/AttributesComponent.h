// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/ActorComponent.h"
#include "AttributesComponent.generated.h"

class UUserWidget;

/** Base Attributes for all characters. */
UENUM(BlueprintType)
enum class EAttributes : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Armors_Proficiency UMETA(DisplayName = "Armors Proficiency"),
	Weapons_Proficiency UMETA(DisplayName = "Weapons Proficiency"),
	Abilities_Proficiency UMETA(DisplayName = "Abilities Proficiency"),
	Level UMETA(DisplayName = "Level"),
	Experience UMETA(DisplayName = "Experience"),
	CurrentHealth UMETA(DisplayName = "Current Health"),
	MaxHealth UMETA(DisplayName = "Max Health"),
	CurrentEnergy UMETA(DisplayName = "Current Energy"),
	MaxEnergy UMETA(DisplayName = "Max Health"),
	CurrentShield UMETA(DisplayName = "Current Shield"),
	MaxShield UMETA(DisplayName = "Max Health"),
	ArmorReduction UMETA(DisplayName = "Armor Reduction"),
	WeaponDamage UMETA(DisplayName = "Weapon Damage"),
	AbilityDamage UMETA(DisplayName = "Ability Damage"),
	Widget UMETA(DisplayName = "UI Widget")
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
		, MaxValue(DefaultValue + BaseValue)
		, CurrentModifier((int32)CurrentValue / 2)
	{}

	/** getter for basevalue */
	float GetBaseValue() const;

	/** getter for currentvalue */
	float GetCurrentValue() const;

	/** setter for currentvalue */
	virtual void SetCurrentValue(const float NewValue);

	/** getter for the modifier */
	int32 GetCurrentModifier() const;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
		float BaseValue = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
		float CurrentValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
		float MaxValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
		int32 CurrentModifier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
		UUserWidget* MainUI;
};

UCLASS()
class PLANETSIX_API UAttributesDataFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/* Getters */

	/** Blueprint Function to return the value of CurrentValue from the struct 
	@Params AttributesData value to get from the struct*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attributes Data Getter")
		static float GetCurrentValue(UPARAM(ref) FAttributesData& AttributesData) { return AttributesData.GetCurrentValue(); }
	/** Blueprint Function to return the value of CurrentValue from the struct
	@Params CurrentValue Current value for a certain value from the struct*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attributes Data Getter")
		static int32 GetCurrentModifier(UPARAM(ref) FAttributesData& AttributesData) { return AttributesData.GetCurrentModifier(); }

	/* Setters */

	/** Blueprint Function to set the value of CurrentValue from the struct
	@Params AttributesData value to set in the struct */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attributes Data Setter")
		static void SetCurrentValue(UPARAM(ref) FAttributesData& AttributesData, const float Value) { AttributesData.SetCurrentValue(Value); }
};

UCLASS(ClassGroup = (Custom), meta = (Blueprintable))
class PLANETSIX_API UAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAttributesComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** armor attribute for the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Main Attributes", ReplicatedUsing = OnRep_ArmorsProficiency)
		FAttributesData ArmorsProficiency;
	/** weapons attribute for the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Main Attributes", ReplicatedUsing = OnRep_WeaponsProficiency)
		FAttributesData WeaponsProficiency;
	/** abilities attribute for the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Main Attributes", ReplicatedUsing = OnRep_AbilitiesProficiency)
		FAttributesData AbilitiesProficiency;
	//------------------------------------------------------------------------------------------------------
	/** Level of the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Level", ReplicatedUsing = OnRep_Level)
		FAttributesData Level;
	/** Experience points for the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Level", ReplicatedUsing = OnRep_Experience)
		FAttributesData Experience;
	/** CurrentHealth attribute for the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health", ReplicatedUsing = OnRep_CurrentHealth)
		FAttributesData CurrentHealth;
	/** CurrentEnergy attribute for the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Energy", ReplicatedUsing = OnRep_CurrentEnergy)
		FAttributesData CurrentEnergy;
	/** CurrentShield attribute for the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Shield", ReplicatedUsing = OnRep_CurrentShield)
		FAttributesData CurrentShield;
	//------------------------------------------------------------------------------------------------------
	/** armor reduction attribute for the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Armor", ReplicatedUsing = OnRep_ArmorReduction)
		FAttributesData ArmorReduction;
	/** weapon damage attribute for the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Damage", ReplicatedUsing = OnRep_WeaponDamage)
		FAttributesData WeaponDamage;
	/** Ability damage attribute for the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Damage", ReplicatedUsing = OnRep_AbilityDamage)
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
	/** Response to current energy being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnCurrentEnergyUpdate();
	/** Response to current shield being updated. Called on the server immediately after modification, and on clients in response to a RepNotify */
	void OnCurrentShieldUpdate();
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
		virtual void OnRep_CurrentEnergy();
	UFUNCTION()
		virtual void OnRep_CurrentShield();
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
