// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseCharacter.h"
#include "Components/BoxComponent.h"
#include "AttributesComponent.h"
#include "EnemyController.h"
#include "Engine.h"
#include "Components/TimelineComponent.h"
#include "PlanetSixEnemy.generated.h"

class APlanetSixCharacter;
class UWeaponComponent;
class UWidgetComponent;
class USkeletalMeshComponent;
class UAnimMontage;
class UEnemyNameWidget;

UCLASS()
class PLANETSIX_API APlanetSixEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlanetSixEnemy(const FObjectInitializer& ObjectInitializer);

	//Enemy Stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
		FString Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
		int32 ID;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
		UAnimMontage* ShootAnimation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
		USoundWave* ShootingSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
		FVector ShootingBegin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
		FVector ShootingEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
		float Experience;

	
	
	UPROPERTY(BlueprintReadWrite, Category = Widget)
		UEnemyNameWidget* NameWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MandatoryToFill)
		TSubclassOf<UUserWidget> NameWidgetClass;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MandatoryToFill)
		UMaterialInterface* EnemyMaterial;
	
		UMaterialInstanceDynamic* DynamicMat;
	
	UPROPERTY(EditAnywhere, Category = MandatoryToFill)
		UCurveFloat* TextureCurve;



	FTimeline MyTimeline;

protected:

	float CurveFloatValue;
	float TimelineValue;
	bool bIsDeadOnce=false;




	UPROPERTY(Category = Movement, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UFloatingPawnMovement* MovComp;
	




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called to do damage calcs and check if Enemy is dead
	//bool IsDead(float damage = 0);

	//// Called upon death to give experience to all players
	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	//	void GiveExperience(TArray<APlanetSixCharacter*> Players, float Exp);

	virtual void Death() override;
	
	
	virtual void EnemyReceieveDamage(ABaseCharacter* Actor) override;
	
	
	int GetID();

	UFUNCTION()
	void DestroyEnemy();

	UFUNCTION()
	void ControlMaterial();
	
	UFUNCTION(BlueprintImplementableEvent)
	void SetWidget();
	
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateWidget();

	
};
