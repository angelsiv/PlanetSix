// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlanetSixPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PLANETSIX_API APlanetSixPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	//Player Stats
		FString UserName;
		int32 Level;

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void ChangeName(const FString& name);
	
	void ChangeName_Implementation(const FString& name);

	UFUNCTION(BlueprintCallable)
	FString GetName();

	// Used to copy properties from the current PlayerState to the passed one
	virtual void CopyProperties(class APlayerState* PlayerState) override;
	// Used to override the current PlayerState with the properties of the passed one
	virtual void OverrideWith(class APlayerState* PlayerState) override;


	virtual void BeginPlay() override;



};
