// Fill out your copyright notice in the Description page of Project Settings.


#include "inventory.h"
#include "Item.h"

inventory::inventory()
{
	*items = new Item[inventorySize];
	
}


inventory::~inventory()
{
}


// Description:
//   add an item to the inventory.
// Parameters:
//   item - Item to add to the inventory.
// Returns:
//   Return true if it was able to add the item, otherwise return false.
//
bool inventory::add(Item item)
{
	int i = 0;

	//look for the first available spot.
	while (i < sizeof(&items)/sizeof(&items[0]))
	{
		//if there is someting
		if (items[i])
		{
			//it item already in inventory
			if (item.id == items[i]->id)
			{
				items[i]->quantity += item.quantity;
				return true;
			}
			else
			{
				//increment spot
				i++;
			}
		}
		//if empty
		else
		{
			//place the item
			items[i] = &item;
			return true;
		}		
	}

	//if there is no spot left
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
Item* inventory::swap(Item *item, int index)
{
	//if the index is out of bound
	if (index<0 || index>sizeof(&items) / sizeof(&items[0]))
	{
		//give back the item you try to put in
		return item;
	}
	else
	{
		//it item is the same
		if (item->id == items[index]->id)
		{
			items[index]->quantity += item->quantity;
			return nullptr;
		}
		else
		{
			//place the item in the spot
			auto *temp = items[index];
			items[index] = item;
			//return what was there (can return null_ptr)
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
Item* inventory::take(int index)
{
	//get the item at the index and set the spot empty
	return swap(nullptr, index);
}

void inventory::sort(sortingMode mode)
{
	heapSort(sizeof(&items) / sizeof(&items[0]), mode);
}

int inventory::compare(Item i1, Item i2, sortingMode mode)
{
	bool result = 0;
	switch (mode)
	{
	case inventory::alphabetical:
		if (i1.displyName > i2.displyName)
		{
			result = 1;
		}
		else if (i1.displyName < i2.displyName)
		{
			result = -1;
		}
		break;
	case inventory::price:
		if (i1.value > i2.value)
		{
			result = 1;
		}
		else if (i1.value < i2.value)
		{
			result = -1;
		}
		break;
	case inventory::weight:
		if (i1.weight > i2.weight)
		{
			result = 1;
		}
		else if (i1.weight < i2.weight)
		{
			result = -1;
		}
		break;
	case inventory::totalPrice:
		if (i1.value * i1.quantity > i2.value * i2.quantity)
		{
			result = 1;
		}
		else if (i1.value * i1.quantity < i2.value * i2.quantity)
		{
			result = -1;
		}
		break;
	case inventory::totalWeight:
		if (i1.weight * i1.quantity > i2.weight * i2.quantity)
		{
			result = 1;
		}
		else if (i1.weight * i1.quantity < i2.weight * i2.quantity)
		{
			result = -1;
		}
		break;
	default:
		break;
	}

	return result;
}

void inventory::heapify( int n, int i,sortingMode mode)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && compare(*items[i],*items[largest],mode)>0)
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && compare(*items[r], *items[largest], mode)>0)
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		auto temp = items[largest];
		items[largest] = items[i];
		items[i] = temp;

		// Recursively heapify the affected sub-tree 
		heapify(n, largest,mode);
	}
}

void inventory::heapSort(int n,sortingMode mode)
{
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(n, i, mode);

	// One by one extract an element from heap 
	for (int i = n - 1; i > 0; i--)
	{
		// Move current root to end 
		auto temp = items[0];
		items[0] = items[i];
		items[i] = temp;

		// call max heapify on the reduced heap 
		heapify( i, 0,mode);
	}
}

