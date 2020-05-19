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

void ASkill::DoDamage(APlanetSixCharacter* AbilityCaster, ESkillDamageType SkillDamageType, APlanetSixCharacter* DamageReceiver)
{
	float AbilityDamage = AbilityCaster->Attributes->AbilityDamage.GetCurrentValue();
	//ability damage depending on their type
	AbilityDamage_Raw = AbilityDamage / DamageFactor_Raw;
	AbilityDamage_AoE = AbilityDamage / DamageFactor_AoE;
	AbilityDamage_DoT = AbilityDamage / DamageFactor_DoT;

	//random chances for critical here

	//
	switch (SkillDamageType)
	{
	case ESkillDamageType::None:
		break;
	case ESkillDamageType::Raw:
		DamageReceiver->ReceiveDamage(AbilityDamage_Raw);
		break;
	case ESkillDamageType::AoE:
		DamageReceiver->ReceiveDamage(AbilityDamage_AoE);
		break;
	case ESkillDamageType::DoT:
		DamageReceiver->ReceiveDamage(AbilityDamage_DoT);
		break;
	default:
		break;
	}
}