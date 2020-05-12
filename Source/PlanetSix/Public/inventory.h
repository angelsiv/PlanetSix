// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class Item;
/**
 * 
 */
class PLANETSIX_API inventory
{
public:
	inventory();
	~inventory();
	bool add(Item item);
	Item* swap(Item *item,int index);
	Item* take(int index);
	
	int inventorySize;
	Item* items[];
	enum sortingMode {alphabetical,price,weight,totalPrice,totalWeight};


	void sort(sortingMode mode);


private:
	void heapify(int n, int i, sortingMode mode);
	void heapSort(int n, sortingMode mode);
	int compare(Item i1, Item i2, sortingMode mode);

};
