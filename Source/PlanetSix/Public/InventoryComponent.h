// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "InventoryComponent.generated.h"

class UTexture2D;
class AItemBase;
class APlanetSixCharacter;
class UDataTable;

USTRUCT(BlueprintType)
struct PLANETSIX_API FItemBaseData : public FTableRowBase  //: public UObject
{
	GENERATED_USTRUCT_BODY()

public:
	// Sets default values for this component's properties
	FItemBaseData(int Id, FString DisplayName, float Weight, float Value, int Quantity, UTexture2D* Icon)
		:id(Id),
		displayName(DisplayName),
		weight(Weight),
		value(Value),
		quantity(Quantity),
		icon(Icon)
	{}
	FItemBaseData()
		:id(0),
		displayName(),
		weight(0),
		value(0),
		quantity(0),
		icon(nullptr)
	{};
	FItemBaseData(FItemBaseData* original)
		:id(original->id),
		displayName(original->displayName),
		weight(original->weight),
		value(original->value),
		quantity(original->quantity),
		icon(original->icon)
	{};



public:
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

	static int compare(FItemBaseData i1, FItemBaseData i2, ECompareField type);

	int getId();
	FString getDisplayName();
	float getWeight();
	float getValue();
	int getQuantity();
	UTexture2D* getIcon();

	float getTotalWeight();
	float getTotalValue();

	bool Stack(FItemBaseData other);

	FItemBaseData GetCopy(FItemBaseData original);

	bool operator==(const FItemBaseData& I) const;


};

USTRUCT(BlueprintType)
struct PLANETSIX_API FCraftableItemData : public FItemBaseData  //: public UObject
{
	GENERATED_USTRUCT_BODY()

public:
	// Sets default values for this component's properties
	FCraftableItemData(float Health, float Shield, float Armor, float WeaponDamage, float AbilityDamage)
		:Health(Health),
		Shield(Shield),
		Armor(Armor),
		WeaponDamage(WeaponDamage),
		AbilityDamage(AbilityDamage)
	{};
	FCraftableItemData()
		:Health(0),
		Shield(0),
		Armor(0),
		WeaponDamage(0),
		AbilityDamage(0)
	{};
	FCraftableItemData(FCraftableItemData* original)
		:Health(original->Health),
		Shield(original->Shield),
		Armor(original->Armor),
		WeaponDamage(original->WeaponDamage),
		AbilityDamage(original->AbilityDamage)
	{};

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Shield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float WeaponDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AbilityDamage;

public:

	static int compare(FCraftableItemData i1, FCraftableItemData i2, ECompareField type);

	int getId() { return id; }
	FString getDisplayName() { return displayName; }
	float getValue() { return value; }
	int getQuantity() { return quantity; }
	UTexture2D* getIcon() { return icon; }
	float GetHealth() { return Health; }
	float GetShield() { return Shield; }
	float GetArmor() { return Armor; }
	float GetWeaponDamage() { return WeaponDamage; }
	float GetAbilityDamage() { return AbilityDamage; }

	float getTotalValue();

	bool Stack(FCraftableItemData other);

	FCraftableItemData GetCopy(FCraftableItemData original);

	bool operator==(const FCraftableItemData& I) const;

};

///Quest Data FORCEINLINES
FORCEINLINE bool FItemBaseData::operator==(const FItemBaseData& I) const
{
	return id == I.id;
}


UENUM(BlueprintType)
enum class ESortingMode : uint8
{
	alphabetical UMETA(DisplayName = "Alphabetical"),
	price UMETA(DisplayName = "Price"),
	weight UMETA(DisplayName = "Weight"),
	totalPrice UMETA(DisplayName = "Total Price"),
	totalWeight UMETA(DisplayName = "Total Weight")
};


UENUM(BlueprintType)
enum class ECompareField : uint8
{
	name UMETA(DisplayName = "name"),
	price UMETA(DisplayName = "Price"),
	weight UMETA(DisplayName = "Weight"),
	id UMETA(DisplayName = "ID"),
	quantity UMETA(DisplayName = "Quantity"),
	Health UMETA(DisplayName = "Health"),
	Shield UMETA(DisplayName = "Shield"),
	Armor UMETA(DisplayName = "Armor"),
	WeaponDMG UMETA(DisplayName = "WeaponDMG"),
	AbilityDMG UMETA(DisplayName = "AbilityDMG")

};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PLANETSIX_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();
	UInventoryComponent(int32 invSize);

	bool add(FItemBaseData item, int  numberOfQuestItems);
	bool add(int Id, int Quantity);
	bool addNormal(FItemBaseData item);
	bool addQuest(FItemBaseData item);

	void RemoveQuestItem(int id, int quantity = 0);

	UFUNCTION(BlueprintCallable)
		FItemBaseData swap(FItemBaseData item, int index);
	UFUNCTION(BlueprintCallable)
		FItemBaseData takeItem(int index);

	void RemoveItem(int id, int quantity);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 inventorySize UMETA(ExposeOnSpawn = "true");
	TArray<FItemBaseData> items;

	TArray<FItemBaseData> QuestItems;

	UFUNCTION(BlueprintCallable)
		TArray<FItemBaseData> GetItems();
	UFUNCTION(BlueprintCallable)
		TArray<FItemBaseData> GetQuestItems();

	UFUNCTION(BlueprintCallable)
		FString Test();

	APlanetSixCharacter* owner;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UDataTable* ItemDataTable;

	FItemBaseData* itemDataPointer;

public:
	// Called when the game starts
	virtual void BeginPlay() override;
	int count = 0;

	void heapify(int n, int i, ESortingMode mode);
	void heapSort(int n, ESortingMode mode);
	//int compare(FitemInv *i1, FitemInv *i2, sortingMode mode);



public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
		int GetCount();
	int GetQuestSize();

	void sort(ESortingMode mode);


};
