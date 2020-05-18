// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MK1_Pistol.generated.h"
class USkeletalMeshComponent;
class UDamageType;

UCLASS()
class PLANETSIX_API AMK1_Pistol : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMK1_Pistol();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* MeshComp;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recoil")
		float RecoilRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recoil")
		float RecoilPitchTop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recoil")
		float RecoilPitchBot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recoil")
		float RecoilYawLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recoil")
		float RecoilYawRight;

	bool isRecoiling;
	float FinalRecoilPitch;
	float FinalRecoilYaw;
	float FinalRecoilYawDirection;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Recoil();

	void StopRecoil();
};
