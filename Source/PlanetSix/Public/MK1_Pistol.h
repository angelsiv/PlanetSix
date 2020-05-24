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
	AMK1_Pistol();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* MeshComp;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Reload();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recoil")
		int CurrentAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recoil")
		int TotalAmmo;

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
	virtual void Tick(float DeltaTime) override;

	void Recoil();

	void StopRecoil();
};
