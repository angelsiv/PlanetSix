// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "itemInv.generated.h"



class AItem_base;
//enum  componentType { Id, Name, Value, Weight, Quantity };

///** Base Attributes for all characters. */
//UENUM(BlueprintType)
//enum class FComponentType : uint8
//{
//	None = 0 UMETA(DisplayName = "None"),
//	Id = 1 UMETA(DisplayName = "Id"),
//	Name = 2 UMETA(DisplayName = "Name"),
//	Abilities_Proficiency = 3 UMETA(DisplayName = "Abilities Proficiency"),
//};


USTRUCT(BlueprintType)
struct PLANETSIX_API FitemInv //: public UObject
{
	GENERATED_USTRUCT_BODY()

public:	
	// Sets default values for this component's properties
	FitemInv() : id(), displayName(), weight(), value(), quantity() {}
	FitemInv(int Id, FString DisplayName, float Weight, float Value, int Quantity) : id(), displayName(), weight(), value(), quantity() {}
	//UitemInv(AItem_base &base);

protected:
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

public:	

	static int compare(FitemInv* i1, FitemInv* i2, int type);

	int getId();
	FString getDisplayName();
	float getWeight();
	float getValue();
	int getQuantity();
	float getTotalWeight();
	float getTotalValue();
	
	bool Stack(FitemInv* other);

	static FitemInv getNewItemInv(int id, FString displayName, float weight, float value, int quantity);
};
