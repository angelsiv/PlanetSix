// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Item_base.generated.h"


class UitemInv;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PLANETSIX_API AItem_base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem_base();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString displayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float weight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int quantity;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadWrite,meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* mesh;
	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		USphereComponent* sphereCollider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* icon;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UFUNCTION(BlueprintCallable)
	//class UitemInv* ToItemInv();
};
