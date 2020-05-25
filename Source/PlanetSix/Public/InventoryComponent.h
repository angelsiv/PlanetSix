// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"



class UTexture2D;


USTRUCT(BlueprintType)
struct PLANETSIX_API FItemData //: public UObject
{
	GENERATED_USTRUCT_BODY()

public:
	// Sets default values for this component's properties
	FItemData(int Id, FString DisplayName, float Weight, float Value, int Quantity, UTexture2D* Icon)
		:id(Id),
		displayName(DisplayName),
		weight(Weight),
		value(Value),
		quantity(Quantity),
		icon(Icon)
	{}
	FItemData()
		:id(0),
		displayName(),
		weight(0),
		value(0),
		quantity(0)
	{};

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* icon;

public:

	static int compare(FItemData* i1, FItemData* i2, int type);

	int getId();
	FString getDisplayName();
	float getWeight();
	float getValue();
	int getQuantity();
	UTexture2D* getIcon();

	float getTotalWeight();
	float getTotalValue();

	bool Stack(FItemData* other);

};

	
UENUM(BlueprintType)
enum class ESortingMode : uint8
{ 
	none UMETA(DisplayName = "None"), 
	alphabetical UMETA(DisplayName = "Alphabetical"),
	price UMETA(DisplayName = "Price"),
	weight UMETA(DisplayName = "Weight"),
	totalPrice UMETA(DisplayName = "Total Price"),
	totalWeight UMETA(DisplayName = "Total Weight")
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PLANETSIX_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent() ;
	UInventoryComponent(int32 invSize);

	UFUNCTION(BlueprintCallable)
	bool add(FItemData item);
	UFUNCTION(BlueprintCallable)
		FItemData swap(FItemData item, int index);
	UFUNCTION(BlueprintCallable)
		FItemData takeItem(int index);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 inventorySize;
	TArray<FItemData> items;

	UFUNCTION(BlueprintCallable)
		TArray<FItemData> GetItems();
	UFUNCTION(BlueprintCallable)
		FString Test();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	bool add(FItemData* item);
	FItemData* swap(FItemData* item, int index);
	FItemData* take(int index);
	int count=0;
	
	void heapify(int n, int i, ESortingMode mode);
	void heapSort(int n, ESortingMode mode);
	//int compare(FitemInv *i1, FitemInv *i2, sortingMode mode);

	

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	int GetCount();

	void sort(ESortingMode mode);


};
