// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributesComponent.h"
#include "Engine.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UAttributesComponent::UAttributesComponent()
	: ArmorsProficiency(1.f)
	, WeaponsProficiency(1.f)
	, AbilitiesProficiency(1.f)
	, Level(1.f)
	, Experience(1.f)
	, CurrentHealth(100.f)
	, MaxHealth(100.f)
	, CurrentEnergy(50.f)
	, MaxEnergy(50.f)
	, CurrentShield(10.f)
	, MaxShield(10.f)
	, ArmorReduction(1.f)
	, WeaponDamage(1.f)
	, AbilityDamage(1.f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	SetIsReplicated(true);
	OwnerPawn = Cast<APawn>(GetOwner());
}

void UAttributesComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UAttributesComponent, ArmorsProficiency);
	DOREPLIFETIME(UAttributesComponent, WeaponsProficiency);
	DOREPLIFETIME(UAttributesComponent, AbilitiesProficiency);
	//-----------------------------------------------------------
	DOREPLIFETIME(UAttributesComponent, Level);
	DOREPLIFETIME(UAttributesComponent, Experience);
	DOREPLIFETIME(UAttributesComponent, CurrentHealth);
	DOREPLIFETIME(UAttributesComponent, MaxHealth);
	DOREPLIFETIME(UAttributesComponent, CurrentEnergy);
	DOREPLIFETIME(UAttributesComponent, MaxEnergy);
	DOREPLIFETIME(UAttributesComponent, CurrentShield);
	DOREPLIFETIME(UAttributesComponent, MaxShield);
	//-----------------------------------------------------------
	DOREPLIFETIME(UAttributesComponent, ArmorReduction);
	DOREPLIFETIME(UAttributesComponent, WeaponDamage);
	DOREPLIFETIME(UAttributesComponent, AbilityDamage);
}

// Called when the game starts
void UAttributesComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

//** getter for base value of attribute */
float FAttributesData::GetBaseValue() const
{
	return BaseValue;
}

//** getter for current value of attribute */
float FAttributesData::GetCurrentValue() const
{
	return CurrentValue;
}

//** setter for current value of attribute */
void FAttributesData::SetCurrentValue(float NewValue)
{
	CurrentValue = NewValue;
}

int32 FAttributesData::GetCurrentModifier() const
{
	return CurrentModifier;
}

void UAttributesComponent::OnArmorsProficiencyUpdate()
{

}

void UAttributesComponent::OnWeaponsProficiencyUpdate()
{

}

void UAttributesComponent::OnAbilitiesProficiencyUpdate()
{

}

void UAttributesComponent::OnLevelUpdate()
{
	//client-specific functionality
	if (OwnerPawn != nullptr && OwnerPawn->IsLocallyControlled())
	{
		FString levelMessage = FString::Printf(TEXT("You are now level %f ."), Level.GetCurrentValue());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, levelMessage);
	}

	//server specific functionality
	if (OwnerPawn != nullptr && OwnerPawn->GetLocalRole() == ROLE_Authority)
	{
		FString levelMessage = FString::Printf(TEXT("%s now is level %f ."), *GetFName().ToString(), Level.GetCurrentValue());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, levelMessage);
	}

	//functions that occur on all machines.
	/** Any special functionality that should occur as a result of leveling should be placed here */

}

void UAttributesComponent::OnExperienceUpdate()
{
	//client-specific functionality
	if (OwnerPawn != nullptr && OwnerPawn->IsLocallyControlled())
	{
		FString expMessage = FString::Printf(TEXT("You now have %f experience."), Experience.GetCurrentValue());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, expMessage);
	}

	//server specific functionality
	if (OwnerPawn != nullptr && OwnerPawn->GetLocalRole() == ROLE_Authority)
	{
		FString expMessage = FString::Printf(TEXT("%s now has %f experience."), *GetFName().ToString(), Experience.GetCurrentValue());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, expMessage);
	}

	//functions that occur on all machines.
	/** Any special functionality that should occur as a result of gaining experience should be placed here */

}

void UAttributesComponent::OnCurrentHealthUpdate()
{
	//client-specific functionality
	if (OwnerPawn != nullptr && OwnerPawn->IsLocallyControlled())
	{
		FString healthMessage = FString::Printf(TEXT("You now have %f health remaining."), CurrentHealth.GetCurrentValue());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, healthMessage);

		if (CurrentHealth.GetCurrentValue() <= 0)
		{
			FString deathMessage = FString::Printf(TEXT("You are dead. Waiting for revive..."));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, deathMessage);
		}
	}

	//server specific functionality
	if (OwnerPawn != nullptr && OwnerPawn->GetLocalRole() == ROLE_Authority)
	{
		FString healthMessage = FString::Printf(TEXT("%s now has %f health remaining."), *GetFName().ToString(), CurrentHealth.GetCurrentValue());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, healthMessage);
	}

	//functions that occur on all machines.
	/** Any special functionality that should occur as a result of damage or death should be placed here */

}

void UAttributesComponent::OnMaxHealthUpdate()
{

}

void UAttributesComponent::OnCurrentEnergyUpdate()
{
	//client-specific functionality
	if (OwnerPawn != nullptr && OwnerPawn->IsLocallyControlled())
	{
		FString energyMessage = FString::Printf(TEXT("You now have %f energy remaining."), CurrentEnergy.GetCurrentValue());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, energyMessage);

		if (CurrentEnergy.GetCurrentValue() <= 0)
		{
			FString zeroMessage = FString::Printf(TEXT("Your energy is depleted... wait for it to recharge or consume an energy bar"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, zeroMessage);
		}
	}

	//server specific functionality
	if (OwnerPawn != nullptr && OwnerPawn->GetLocalRole() == ROLE_Authority)
	{
		FString energyMessage = FString::Printf(TEXT("%s now has %f energy remaining."), *GetFName().ToString(), CurrentEnergy.GetCurrentValue());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, energyMessage);
	}

	//functions that occur on all machines.
	/** Any special functionality that should occur as a result of lack of energy should be placed here */

	//CurrentEnergy.SetCurrentValue(0.f);
}

void UAttributesComponent::OnMaxEnergyUpdate()
{

}

void UAttributesComponent::OnCurrentShieldUpdate()
{
	//client-specific functionality
	if (OwnerPawn != nullptr && OwnerPawn->IsLocallyControlled())
	{
		FString shieldMessage = FString::Printf(TEXT("You now have %f shield remaining."), CurrentShield.GetCurrentValue());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, shieldMessage);

		if (CurrentShield.GetCurrentValue() <= 0)
		{
			FString zeroMessage = FString::Printf(TEXT("Your shield is depleted."));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, zeroMessage);
		}
	}

	//server specific functionality
	if (OwnerPawn != nullptr && OwnerPawn->GetLocalRole() == ROLE_Authority)
	{
		FString shieldMessage = FString::Printf(TEXT("%s now has %f shield remaining."), *GetFName().ToString(), CurrentShield.GetCurrentValue());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, shieldMessage);
	}

	//functions that occur on all machines.
	/** Any special functionality that should occur as a result of damage to shield or lack of shield should be placed here */

}

void UAttributesComponent::OnMaxShieldUpdate()
{

}

void UAttributesComponent::OnArmorReductionUpdate()
{

}

void UAttributesComponent::OnWeaponDamageUpdate()
{

}

void UAttributesComponent::OnAbilityDamageUpdate()
{

}

#pragma region OnRep_Attributes
//this is all for rep_notifies : everytime a value is changed, the engine calls this for multiplayer purposes
void UAttributesComponent::OnRep_ArmorsProficiency() { UAttributesComponent::OnArmorsProficiencyUpdate(); }
void UAttributesComponent::OnRep_WeaponsProficiency() { UAttributesComponent::OnWeaponsProficiencyUpdate(); }
void UAttributesComponent::OnRep_AbilitiesProficiency() { UAttributesComponent::OnAbilitiesProficiencyUpdate(); }
//-----------------------------------------------------------------------------------------------------------------
void UAttributesComponent::OnRep_Level() { UAttributesComponent::OnLevelUpdate(); }
void UAttributesComponent::OnRep_Experience() { UAttributesComponent::OnExperienceUpdate(); }
void UAttributesComponent::OnRep_CurrentHealth() { UAttributesComponent::OnCurrentHealthUpdate(); }
void UAttributesComponent::OnRep_MaxHealth() { UAttributesComponent::OnMaxHealthUpdate(); }
void UAttributesComponent::OnRep_CurrentEnergy() { UAttributesComponent::OnCurrentEnergyUpdate(); }
void UAttributesComponent::OnRep_MaxEnergy() { UAttributesComponent::OnMaxEnergyUpdate(); }
void UAttributesComponent::OnRep_CurrentShield() { UAttributesComponent::OnCurrentShieldUpdate(); }
void UAttributesComponent::OnRep_MaxShield() { UAttributesComponent::OnMaxShieldUpdate(); }
//-----------------------------------------------------------------------------------------------------------------
void UAttributesComponent::OnRep_ArmorReduction() { UAttributesComponent::OnArmorReductionUpdate(); }
void UAttributesComponent::OnRep_WeaponDamage() { UAttributesComponent::OnWeaponDamageUpdate(); }
void UAttributesComponent::OnRep_AbilityDamage() { UAttributesComponent::OnAbilityDamageUpdate(); }
#pragma endregion