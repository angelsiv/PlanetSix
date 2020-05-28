// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class USkeletalMeshComponent;
class UDamageType;
class APlanetSixCharacter;

UCLASS()
class PLANETSIX_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Base Components")
		USkeletalMeshComponent* SKMeshComponent;

	/** ammo currently stored in the magazine. when shooting, this is the ammo used. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
		int32 AmmoInMagazine;

	/** max ammo that can fit inside a magazine. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
		int32 AmmoMaxInMagazine;

	/** Reload Speed of the weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
		float ReloadSpeed;

	/** Fire rate of the weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
		float FireRate;

	/** when shooting, percentage of recoil */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recoil")
		float RecoilRate;

	/** when shooting, recoil towards up */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recoil")
		float RecoilPitchTop;

	/** when shooting, recoil towards bottom */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recoil")
		float RecoilPitchBot;

	/** when shooting, recoil towards left */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recoil")
		float RecoilYawLeft;

	/** when shooting, recoil towards right */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recoil")
		float RecoilYawRight;

	bool bIsRecoiling;
	float FinalRecoilPitch;
	float FinalRecoilYaw;
	float FinalRecoilYawDirection;

	//---------------------------------------------------------------------------
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Damage")
		TSubclassOf<UDamageType> DamageType;
	//---------------------------------------------------------------------------

	/** Fires the gun when activated */
	UFUNCTION(BlueprintCallable, Category = "Shoot Mechanics")
		void Fire();

	/** Reloads the gun when activated */
	UFUNCTION(BlueprintCallable, Category = "Shoot Mechanics")
		void Reload();

	void Recoil();
	void StopRecoil();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	APlanetSixCharacter* OwnerPlayer;
};
