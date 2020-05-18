// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill.h"
#include "PlanetSixCharacter.h"

// Sets default values
ASkill::ASkill()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASkill::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASkill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Calculate damage depending on ability damage from the ability caster
void ASkill::CalculateDamage(APlanetSixCharacter* AbilityCaster)
{
	float AbilityDamage = AbilityCaster->Attributes->AbilityDamage.GetCurrentValue();
	//ability damage depending on their type
	AbilityDamage_Raw = AbilityDamage / DamageFactor_Raw;
	AbilityDamage_AoE = AbilityDamage / DamageFactor_AoE;
	AbilityDamage_DoT = AbilityDamage / DamageFactor_DoT;

	//random chances for critical here

}

float ASkill::OutgoingDamage(ESkillDamageType SkillDamageType)
{
	CalculateDamage(Character);
	switch (SkillDamageType)
	{
	case ESkillDamageType::None:
		break;
	case ESkillDamageType::Raw:
		return AbilityDamage_Raw;
		break;
	case ESkillDamageType::AoE:
		return AbilityDamage_AoE;
		break;
	case ESkillDamageType::DoT:
		return AbilityDamage_DoT;
		break;
	default:
		break;
	}
	return 1.f;
}