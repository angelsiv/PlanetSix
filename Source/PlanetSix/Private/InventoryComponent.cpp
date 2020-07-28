// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"
#include "PlanetSixCharacter.h"
#include "PLanetSixGameInstance.h"
#include "ItemBase.h"
#include "Engine.h"

#define PRINT(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::Black,text)


#pragma region Inventory

UInventoryComponent::UInventoryComponent()
{
    items = TArray<FItemBaseData>();
    items.Init(FItemBaseData(), 10);
    QuestItems = TArray<FItemBaseData>();
    //GEngine->AddOnScreenDebugMessage(1, 10, FColor::Emerald, TEXT("fewqef "));
    inventorySize = 10;
}



// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent(int32 invSize)
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    inventorySize = invSize;

    //items.Init(nullptr, inventorySize);


    // ...
}


TArray<FItemBaseData> UInventoryComponent::GetItems()
{
    return items;
}
TArray<FItemBaseData> UInventoryComponent::GetQuestItems()
{
    return QuestItems;
}

FString UInventoryComponent::Test()
{
    return FString::FromInt(items.Num());
}

void UInventoryComponent::UseItem(int index, APlanetSixCharacter* player)
{
    bool temp = items[index].Use(player);
    GEngine->AddOnScreenDebugMessage(1, 1.5, FColor::Purple, FString().FromInt(items[index].use.DestroyItemOnUse));
    if (items[index].Use(player))
    {
        this->RemoveItem(items[index].id, 1);
    }
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
    Super::BeginPlay();

    // ...

}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
}

int UInventoryComponent::GetCount()
{
    return count;
}

int UInventoryComponent::GetQuestSize()
{
    return QuestItems.Num();
}


// Description:
//   add an item to the inventory.
// Parameters:
//   item - Item to add to the inventory.
// Returns:
//   Return true if it was able to add the item, otherwise return false.
//
bool UInventoryComponent::addNormal(FItemBaseData item)
{
    auto x = Cast<UPlanetSixGameInstance>(owner->GetGameInstance());


    //look for the same item in inv
    for (int i = 0; i < items.Num(); i++)
    {
        //if same id
        if (items[i].getId() == item.id)
        {
            if (items[i].Stack(item))
            {
                return true;
            }
        }
    }
    //look for the first available spot.
    for (int i = 0; i < items.Num(); i++)
    {
        //if there is someting
        if (!items[i].getId() == 0)
        {
            //it item already in inventory
            //return items[i].Stack(item);

            if (items[i].Stack(item))
            {
                return true;
            }

        }
        //if empty
        else
        {
            //place the item
            items[i] = item;
            count++;
            return true;
        }
    }


    x->AddItemsToinventoryplayer(items);

    //if there is no spot left
    return false;
}

bool UInventoryComponent::addQuest(FItemBaseData item)
{
    //look for the first available spot.
    for (int i = 0; i < QuestItems.Num(); i++)
    {
        //if there is someting
        if (!QuestItems[i].getId() == 0)
        {
            //it item already in inventory
            //return items[i].Stack(item);

            if (QuestItems[i].Stack(item))
            {
                return true;
            }

        }
        //if empty
        else
        {
            //place the item
            QuestItems[i] = item;
            return true;
        }
    }

    QuestItems.Add(item);


    //if there is no spot left
    return false;
}

void UInventoryComponent::RemoveQuestItem(int id, int quantity)
{
    for (size_t i = 0; i < QuestItems.Num(); i++)
    {
        if (QuestItems[i].id == id)
        {
            if (quantity < 1)
            {
                auto itemId = FItemBaseData();
                itemId.id = id;
                QuestItems.RemoveSingle(itemId);
            }
            else
            {
                QuestItems[i].quantity -= quantity;
            }
        }
    }

}

// Description:
//   add an item to the inventory.
// Parameters:
//   item - Item to add to the inventory.
//	  numberOfQuestItems - Number of items to put in the quest inventory
// Returns:
//   Return true if it was able to add the item, otherwise return false.
//
bool UInventoryComponent::add(FItemBaseData item, int  numberOfQuestItems = 0)
{
    if (numberOfQuestItems > item.quantity)
    {
        numberOfQuestItems = item.quantity;
    }

    if (numberOfQuestItems > 0)
    {
        FItemBaseData QuestItem = FItemBaseData(&item);
        QuestItem.quantity = numberOfQuestItems;
        if (!addQuest(QuestItem))
        {
            owner->ItemPickup();
        }
    }

    if (item.quantity - numberOfQuestItems > 0)
    {
        FItemBaseData NormalItem = FItemBaseData(&item);
        NormalItem.quantity = item.quantity - numberOfQuestItems;
        return addNormal(NormalItem);

    }
    return true;
}

bool UInventoryComponent::add(int Id, int Quantity)
{
    static const FString contextString(TEXT("ItemDataTable"));
    FName IdName = FName(*FString::FromInt(Id));
    itemDataPointer = ItemDataTable->FindRow<FItemBaseData>(IdName, contextString, true);
    auto itemData = FItemBaseData();
    if (itemDataPointer)
    {
        itemData.id = itemDataPointer->getId();
        itemData.displayName = itemDataPointer->getDisplayName();
        itemData.value = itemDataPointer->getValue();
        itemData.weight = itemDataPointer->getWeight();
        itemData.icon = itemDataPointer->getIcon();
        itemData.use = itemDataPointer->use;
        itemData.quantity = Quantity;
        return add(itemData);
    }
    return false;
}

// Description:
//   Place an item in a specific inventory spot.
// Parameters:
//   item - Item to add to the inventory.
//   index - Index of the inventory spot.
// Return:
//   Return the Item in that spot.
//

FItemBaseData UInventoryComponent::swap(FItemBaseData item, int index)
{
    //if the index is out of bound
    if (index < 0 || index > items.Num())
    {
        //give back the item you try to put in
        return item;
    }
    else
    {
        //it item is the same
        if (FItemBaseData::compare(item, items[index], ECompareField::id) == 0)
        {
            items[index].Stack(item);
            return FItemBaseData();


        }
        else
        {
            //place the item in the spot
            auto temp = items[index];
            items[index] = item;
            //return what was there 
            return temp;
        }
    }
}


// Description:
//   Take an item in a specific inventory spot.
// Parameters:
//   index - Index of the inventory spot.
// Return:
//   Return the Item in that spot.
//

FItemBaseData UInventoryComponent::takeItem(int index)
{
    return swap(FItemBaseData(), index);
}

void UInventoryComponent::RemoveItem(int id, int quantity)
{
    for (size_t i = 0; i < items.Num(); i++)
    {
        if (items[i].id == id)
        {
            if (quantity < 0 || items[i].quantity <= quantity)
            {
                takeItem(i);
            }
            else
            {
                items[i].quantity -= quantity;
            }
        }
    }
}






#pragma endregion

// Sets default values for this component's properties
#pragma region ItemBaseData


FItemBaseData FItemBaseData::GetCopy(FItemBaseData original)
{
    return FItemBaseData(original.id, original.displayName, original.weight, original.value, original.quantity, original.icon, original.use);
}


int FItemBaseData::compare(FItemBaseData  i1, FItemBaseData  i2, ECompareField type)
{

    int result = 0;
    switch (type)
    {
    case ECompareField::name:
        if (i1.displayName > i2.displayName)
        {
            result = 1;
        }
        else if (i1.displayName < i2.displayName)
        {
            result = -1;
        }
        break;
    case ECompareField::price:
        if (i1.value > i2.value)
        {
            result = 1;
        }
        else if (i1.value < i2.value)
        {
            result = -1;
        }
        break;
    case ECompareField::weight:
        if (i1.weight > i2.weight)
        {
            result = 1;
        }
        else if (i1.weight < i2.weight)
        {
            result = -1;
        }
        break;
    case ECompareField::id:
        if (i1.id > i2.id)
        {
            result = 1;
        }
        else if (i1.id < i2.id)
        {
            result = -1;
        }
        break;
    case ECompareField::quantity:
        if (i1.quantity > i2.quantity)
        {
            result = 1;
        }
        else if (i1.quantity < i2.quantity)
        {
            result = -1;
        }
        break;
    default:
        break;
    }

    return result;
}


int FItemBaseData::getId()
{
    return id;
}

FString FItemBaseData::getDisplayName()
{
    return displayName;
}

float FItemBaseData::getWeight()
{
    return weight;
}

float FItemBaseData::getValue()
{
    return value;
}

int FItemBaseData::getQuantity()
{
    return quantity;
}

float FItemBaseData::getTotalWeight()
{
    return weight * quantity;
}

float FItemBaseData::getTotalValue()
{
    return value * quantity;
}

UTexture2D* FItemBaseData::getIcon()
{
    return icon;
}

bool FItemBaseData::Use(APlanetSixCharacter* player)
{
    PRINT("using Item", -1);
    return use.Use(player);
}

bool FItemBaseData::Stack(FItemBaseData other)
{
    if (id == other.id)
    {
        quantity += other.quantity;
        return true;
    }
    else
    {
        return false;
    }
}
#pragma endregion


bool FUseData::Use(APlanetSixCharacter* player)
{
    int x = (int)UseType;
    FString s = s.FromInt(x);
    GEngine->AddOnScreenDebugMessage(1, 1.5, FColor::Magenta, s);
    bool used = true;
    switch (UseType)
    {
    default:
    case EUseTypes::none:
        break;
    case EUseTypes::heal:
        used = Heal(player);
        break;
    case EUseTypes::crystal:
        EquipCrystal(player);
        break;
    }
    return DestroyItemOnUse && used;
}

bool FUseData::Heal(APlanetSixCharacter* player)
{
    for (size_t i = Fvalues.Num(); i < 1; i++)
    {
        Fvalues.Add(0);
    }
    if (player->Attributes->Health.GetCurrentValue() < player->Attributes->Health.GetMaxValue())
    {
        player->HealthRegen(Fvalues[0]);
        return true;
    }
    return false;
}

void FUseData::EquipCrystal(APlanetSixCharacter* player)
{
    for (size_t i = Fvalues.Num(); i < 5; i++)
    {
        Fvalues.Add(0);
    }

    for (size_t i = Bvalues.Num(); i < 1; i++)
    {
        Bvalues.Add(0);
    }

    int armorValue = Fvalues[0];
    int abilityValue = Fvalues[1];
    int healthValue = Fvalues[2];
    int weaponValue = Fvalues[3];
    int shieldValue = Fvalues[4];

    if (Bvalues[0])
    {
        armorValue *= -1;
        abilityValue *= -1;
        healthValue *= -1;
        weaponValue *= -1;
        shieldValue *= -1;
    }
    player->Attributes->Health.BaseValue += healthValue;
    player->Attributes->AbilityDamage.BaseValue += abilityValue;
    player->Attributes->ArmorReduction.BaseValue += armorValue;
    player->Attributes->WeaponDamage.BaseValue += weaponValue;
    player->Attributes->Shield.BaseValue += shieldValue;
    Bvalues[0] = !Bvalues[0];
    PRINT("crystal", 1);
}

