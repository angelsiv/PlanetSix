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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USkeletalMeshComponent* MeshComp;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* VR_MuzzleLocation;

public:	
	virtual void Tick(float DeltaTime) override;

};
