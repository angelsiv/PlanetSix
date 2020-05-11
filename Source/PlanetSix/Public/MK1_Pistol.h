// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MK1_Pistol.generated.h"
class USkeletalMeshComponent;

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
