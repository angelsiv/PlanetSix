// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapTravel.generated.h"

class UBoxComponent;
class UTextRenderComponent;
class USoundCue;

UCLASS()
class PLANETSIX_API AMapTravel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapTravel();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true")) 
		UStaticMeshComponent* MeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true")) 
		UBoxComponent* BoxCollider;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true")) 
		UTextRenderComponent* LocationText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map") 
		FString LevelName;

	UPROPERTY(BlueprintReadOnly, Category = "Audio")
		USoundCue* PortalUseSoundCue;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void TravelTo();
};
