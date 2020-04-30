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
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...

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

}

void UAttributesComponent::OnRep_MaxHealth()
{

}

void UAttributesComponent::OnRep_CurrentEnergy()
{

}

void UAttributesComponent::OnRep_MaxEnergy()
{

}
void UAttributesComponent::OnRep_CurrentShield()
{

}