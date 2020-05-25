// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MK1_GrenadeLauncher.generated.h"

UCLASS()
class PLANETSIX_API AMK1_GrenadeLauncher : public AActor
{
	GENERATED_BODY()

public:	
	AMK1_GrenadeLauncher();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		USkeletalMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = Mesh, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* MuzzleLocation;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		TSubclassOf<class AGrenadeLauncherProjectile> GrenadeProjectile;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void Fire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void Reload();

	UWorld* WRLD;

public:	
	virtual void Tick(float DeltaTime) override;

};
