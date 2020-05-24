// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapTravel.generated.h"

class UBoxComponent;
class UTextRenderComponent;

UCLASS()
class PLANETSIX_API AMapTravel : public AActor
{
	GENERATED_BODY()
	
public:	
	FString MapName;
	// Sets default values for this actor's properties
	AMapTravel();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true")) UStaticMeshComponent* MeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true")) UBoxComponent* BoxCollider;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true")) UTextRenderComponent* LocationText;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void TravelTo(FString mapName);
};
