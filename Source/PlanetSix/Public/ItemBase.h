// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryComponent.h"
#include "Components/SphereComponent.h"
#include "ItemBase.generated.h"



//struct FitemInv;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PLANETSIX_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DestroyOnPickup=true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadWrite,meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* mesh;
	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		USphereComponent* sphereCollider;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FItemBaseData itemData UMETA(ExposeOnSpawn = "true");

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		FItemBaseData ToItemInv();

	void Init(FItemBaseData item);

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
