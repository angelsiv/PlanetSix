// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributesComponent.h"
#include "Engine.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UAttributesComponent::UAttributesComponent()
	: Brawn(1.f)
	, Vitality(1.f)
	, Agility(1.f)
	, Mind(1.f)
	, Social(1.f)
	, Fate(1.f)
	, CurrentHealth(1.f)
	, MaxHealth(1.f)
	, CurrentEnergy(1.f)
	, MaxEnergy(1.f)
	, CurrentShield(1.f)
	, Experience(1.f)
	, Level(1.f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	bReplicates = true;
	bAutoActivate = true;
	OwnerPawn = Cast<APawn>(GetOwner());
}

void UAttributesComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>&OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UAttributesComponent, Brawn);
	DOREPLIFETIME(UAttributesComponent, Vitality);
	DOREPLIFETIME(UAttributesComponent, Agility);
	DOREPLIFETIME(UAttributesComponent, Mind);
	DOREPLIFETIME(UAttributesComponent, Social);
	DOREPLIFETIME(UAttributesComponent, Fate);
	DOREPLIFETIME(UAttributesComponent, CurrentHealth);
	DOREPLIFETIME(UAttributesComponent, MaxHealth);
	DOREPLIFETIME(UAttributesComponent, CurrentEnergy);
	DOREPLIFETIME(UAttributesComponent, MaxEnergy);
	DOREPLIFETIME(UAttributesComponent, CurrentShield);
	DOREPLIFETIME(UAttributesComponent, Experience);
	DOREPLIFETIME(UAttributesComponent, Level);
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

//** setter for base value of attribute */
void FAttributesData::SetBaseValue(float NewValue)
{
	BaseValue = NewValue;
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

void UAttributesComponent::OnHealthUpdate()
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

void UAttributesComponent::OnEnergyUpdate()
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
	/** Any special functionality that should occur as a result of damage or death should be placed here */

	//CurrentEnergy.SetCurrentValue(0.f);
}

void UAttributesComponent::OnShieldUpdate()
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
	/** Any special functionality that should occur as a result of damage or death should be placed here */

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
	/** Any special functionality that should occur as a result of damage or death should be placed here */

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
	/** Any special functionality that should occur as a result of damage or death should be placed here */

}

#pragma region OnRep_Attributes
void UAttributesComponent::OnRep_Brawn()
{

}
void UAttributesComponent::OnRep_Vitality()
{

}
void UAttributesComponent::OnRep_Agility()
{

}
void UAttributesComponent::OnRep_Mind()
{

}
void UAttributesComponent::OnRep_Social()
{

}
void UAttributesComponent::OnRep_Fate()
{

}
void UAttributesComponent::OnRep_CurrentHealth()
{
	UAttributesComponent::OnHealthUpdate();
}
void UAttributesComponent::OnRep_MaxHealth()
{

}
void UAttributesComponent::OnRep_CurrentEnergy()
{
	UAttributesComponent::OnEnergyUpdate();
}
void UAttributesComponent::OnRep_MaxEnergy()
{

}
void UAttributesComponent::OnRep_CurrentShield()
{
	UAttributesComponent::OnShieldUpdate();
}
void UAttributesComponent::OnRep_Experience()
{
	UAttributesComponent::OnExperienceUpdate();
}
void UAttributesComponent::OnRep_Level()
{
	UAttributesComponent::OnLevelUpdate();
}
#pragma endregion