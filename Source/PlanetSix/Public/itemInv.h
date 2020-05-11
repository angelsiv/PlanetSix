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


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),BlueprintType )
class PLANETSIX_API UitemInv : public UObject
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UitemInv();
	UitemInv(int Id, FString DisplayName, float Weight, float Value, int Quantity);// :id(0), displayName(), weight(1.0f), value(1.f), quantity(1);
	//UitemInv(AItem_base &base);

	UitemInv * self;

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

	static int compare(UitemInv* i1, UitemInv* i2, int type);

	int getId();
	FString getDisplayName();
	float getWeight();
	float getValue();
	int getQuantity();
	float getTotalWeight();
	float getTotalValue();
	
	bool Stack(UitemInv* other);

	//static UitemInv getNewItemInv(int id, FString displayName, float weight, float value, int quantity);
};
