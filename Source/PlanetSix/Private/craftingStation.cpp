// This work is the sole property of 2Pow6 Games.

#include "InventoryComponent.h"
#include "craftingStation.h"

// Sets default values
AcraftingStation::AcraftingStation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//boxcomponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

}

// Called when the game starts or when spawned
void AcraftingStation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AcraftingStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FCraftingRecipe> AcraftingStation::GetRecipies()
{
	return PossibleRecipies;
}

FCraftingRecipe AcraftingStation::GetRecipe(int index)
{
	return PossibleRecipies[index];
}

void AcraftingStation::LoadRecipies(TArray<FItemBaseData> inventory)
{

	//get all recipes from dataTable

	PossibleRecipies = GetRecipeFromDataTable();
	VeriyCraftability(inventory);
}

void AcraftingStation::Craft(int index, UInventoryComponent* inventory)
{
	Craft(PossibleRecipies[index], inventory);
}

void AcraftingStation::Craft(FCraftingRecipe Recipe, UInventoryComponent* inventory)
{
	for (auto& Elem : Recipe.ingredients)
	{
		inventory->RemoveItem(Elem.Key, Elem.Value);
	}
	inventory->add(Recipe.product.id, Recipe.product.quantity);
	VeriyCraftability(inventory->GetItems());
}

void AcraftingStation::VeriyCraftability(TArray<FItemBaseData> inventory)
{
	TMap<int, int> AvailableItems;
	PossibleRecipies.Empty();
	//add all item in the inventory to a hashMap for fast checking 
	for (size_t i = 0; i < inventory.Num(); i++)
	{
		AvailableItems.Add(inventory[i].getId(), inventory[i].getQuantity());
	}

	///check that all item needed for recipes are in inventory
	//check all recipes
	for (size_t i = 0; i < PossibleRecipies.Num(); i++)
	{
		///check all items are present in inventory and in sufficent number
		//check all items
		for (auto& Elem : PossibleRecipies[i].ingredients)
		{
			//check item is in inventory
			if (AvailableItems.Contains(Elem.Key))
			{
				//check there is enough items
				PossibleRecipies[i].craftable = AvailableItems[Elem.Key] >= Elem.Value;

			}

		}

	}
}


TArray<FCraftingRecipe> AcraftingStation::GetRecipeFromDataTable()
{
	auto output = TArray<FCraftingRecipe>();
	static const FString contextString(TEXT("ItemDataTable"));
	TArray<FName> RowNames;
	RowNames = RecipeTable->GetRowNames();

	for (auto& name : RowNames)
	{
		FCraftingRecipe* row = RecipeTable->FindRow<FCraftingRecipe>(name, contextString, true);
		if (row)
		{
			auto r = FCraftingRecipe();
			r.ingredients = row->ingredients;
			r.product = row->product;
			
			output.Add(r);
		}
	}
	return output;
}


