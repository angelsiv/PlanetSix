// Fill out your copyright notice in the Description page of Project Settings.


#include "inventory.h"
//#include "itemInv.h"


// Sets default values for this component's properties
Uinventory::Uinventory(int32 invSize)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	inventorySize = invSize;

	//items.Init(nullptr, inventorySize);


	// ...
}


TArray<FitemInv> Uinventory::GetItems()
{
	return items;
}

// Called when the game starts
void Uinventory::BeginPlay()
{
	//Super::BeginPlay();

	// ...

}


// Called every frame
void Uinventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void Uinventory::sort(sortingMode mode)
{
}


// Description:
//   add an item to the inventory.
// Parameters:
//   item - Item to add to the inventory.
// Returns:
//   Return true if it was able to add the item, otherwise return false.
//
bool Uinventory::add(FitemInv* item)
{
	//return false;
	
	//look for the first available spot.
	for (int i = 0; i < sizeof(&items) / sizeof(&items[0]);i++)
	{
		//if there is someting
		if (!items[i].getId()==0)
		{
			////it item already in inventory
			//if (items[i].Stack(item))
			//{
			//	return true;
			//}
		}
		//if empty
		else
		{
			//place the item
			//items[i] = *item;
			return true;
		}
		return false;
	}

	//if there is no spot left
	return false;
}
bool Uinventory::add(FitemInv item)
{
	return add(&item);
}

// Description:
//   Place an item in a specific inventory spot.
// Parameters:
//   item - Item to add to the inventory.
//   index - Index of the inventory spot.
// Return:
//   Return the Item in that spot.
//
FitemInv* Uinventory::swap(FitemInv* item, int index)
{
	//if the index is out of bound
	if (index < 0 || index>sizeof(&items) / sizeof(&items[0]))
	{
		//give back the item you try to put in
		return item;
	}
	else
	{
		//it item is the same
		if (FitemInv::compare(item, &items[index], 1) == 0)
		{
			items[index].Stack(item);
			return nullptr;
		}
		else
		{
			//place the item in the spot
			//auto temp = items[index];
			items[index] = *item;
			//return what was there (can return null_ptr)
			//return &temp;
			return nullptr; //debug purposed -Alonso
		}
	}
}
FitemInv Uinventory::swap(FitemInv item, int index)
{
	return *swap(&item, index);
}


// Description:
//   Take an item in a specific inventory spot.
// Parameters:
//   index - Index of the inventory spot.
// Return:
//   Return the Item in that spot.
//
FitemInv* Uinventory::take(int index)
{
	//get the item at the index and set the spot empty
	return swap(nullptr, index);
}
FitemInv Uinventory::takeItem(int index)
{
	return *take(index);
}


//
//int Uinventory::compare(FitemInv* i1, FitemInv* i2, sortingMode mode)
//{
//	switch (mode)
//	{
//	case Uinventory::alphabetical:
//		return FitemInv::compare(i1, i2, 1);
//	case Uinventory::price:
//		return FitemInv::compare(i1, i2, 1);
//	case Uinventory::weight:
//		return FitemInv::compare(i1, i2, 1);
//	case Uinventory::totalPrice:
//		if (i1->getTotalValue() > i2->getTotalValue())
//		{
//			return 1;
//		}
//		else if (i1->getTotalValue() < i2->getTotalValue())
//		{
//			return -1;
//		}
//		break;
//	case Uinventory::totalWeight:
//		if (i1->getTotalWeight() > i2->getTotalWeight())
//		{
//			return 1;
//		}
//		else if (i1->getTotalWeight() < i2->getTotalWeight())
//		{
//			return -1;
//		}
//		break;
//	default:
//		break;
//	}
//
//	return 0;
//}

void Uinventory::heapify(int n, int i, sortingMode mode)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	//if (l < n && compare(items[i], items[largest], mode)>0)
		//largest = l;

	// If right child is larger than largest so far 
	//if (r < n && compare(items[r], items[largest], mode)>0)
		//largest = r;

	// If largest is not root 
	if (largest != i)
	{
		auto temp = items[largest];
		items[largest] = items[i];
		items[i] = temp;

		// Recursively heapify the affected sub-tree 
		heapify(n, largest, mode);
	}
}

void Uinventory::heapSort(int n, sortingMode mode)
{
}



