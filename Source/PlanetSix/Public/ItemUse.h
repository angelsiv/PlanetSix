// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemUse.generated.h"

class APlanetSixCharacter;

UCLASS()
class PLANETSIX_API AItemUse : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemUse();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
		virtual void Use(APlanetSixCharacter* player);

};
