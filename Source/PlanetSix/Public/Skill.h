// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Skill.generated.h"

class APlanetSixCharacter;

/** Types of damage for skills. 
@ Raw is blunt damage
@ AoE is area of effect (zone)
@ DoT is damage over time (every second) */
UENUM(BlueprintType)
enum class ESkillDamageType : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Raw = 1 UMETA(DisplayName = "Raw Damage"),
	AoE = 2 UMETA(DisplayName = "Area of Effect Damage"),
	DoT = 4 UMETA(DisplayName = "Damage over Time"),
};

UCLASS()
class PLANETSIX_API ASkill : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkill();
	UPROPERTY(EditAnywhere)
		APlanetSixCharacter* Character;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		float OutputDamage;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		float CharacterAbilityDamage;
	const float DamageFactor_Raw = 5.f;
	const float DamageFactor_AoE = 7.f;
	const float DamageFactor_DoT = 8.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float AbilityDamage_Raw;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float AbilityDamage_AoE;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float AbilityDamage_DoT;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void CalculateDamage(APlanetSixCharacter* AbilityCaster);
	UFUNCTION()
		float OutgoingDamage(ESkillDamageType SkillDamageType);
};
