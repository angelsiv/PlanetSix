// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "itemInv.h"
#include "inventory.generated.h"


//struct FitemInv;


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PLANETSIX_API Uinventory : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	Uinventory() {};
	Uinventory(int32 invSize);

	UFUNCTION(BlueprintCallable)
	bool add(FitemInv item);
	UFUNCTION(BlueprintCallable)
	FitemInv swap(FitemInv item, int index);
	UFUNCTION(BlueprintCallable)
	FitemInv takeItem(int index);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 inventorySize;
	TArray<FitemInv> items;
	enum sortingMode { alphabetical, price, weight, totalPrice, totalWeight };

	UFUNCTION(BlueprintCallable)
		TArray<FitemInv> GetItems();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	bool add(FitemInv* item);
	FitemInv* swap(FitemInv* item, int index);
	FitemInv* take(int index);
	
	void heapify(int n, int i, sortingMode mode);
	void heapSort(int n, sortingMode mode);
	//int compare(FitemInv *i1, FitemInv *i2, sortingMode mode);


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void sort(sortingMode mode);

};