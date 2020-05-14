// Fill out your copyright notice in the Description page of Project Settings.


#include "itemInv.h"
#include "Item_base.h"
#include "ItemInv.h"

// Sets default values for this component's properties
FitemInv::FitemInv()
{

}
FitemInv::FitemInv(int Id, FString DisplayName, float Weight, float Value, int Quantity): id(), displayName(),  weight(),  value(),  quantity()
{
	id = Id;
	displayName = DisplayName;
	value = Value;
	weight = Weight;
	quantity = Quantity;
}
//UitemInv::UitemInv(AItem_base &base)
//{
//	id = base.id;
//	displayName = base.displayName;
//	value = base.value;
//	weight = base.weight;
//	quantity = base.quantity;
//}

int FitemInv::compare(FitemInv * i1, FitemInv * i2, int type)
{

	int result = 0;
	switch (type)
	{
	case 1:
		if (i1->displayName > i2->displayName)
		{
			result = 1;
		}
		else if (i1->displayName < i2->displayName)
		{
			result = -1;
		}
		break;
	case 2:
		if (i1->value > i2->value)
		{
			result = 1;
		}
		else if (i1->value < i2->value)
		{
			result = -1;
		}
		break;
	case 3:
		if (i1->weight > i2->weight)
		{
			result = 1;
		}
		else if (i1->weight < i2->weight)
		{
			result = -1;
		}
		break;
	case 4:
		if (i1->value * i1->quantity > i2->value * i2->quantity)
		{
			result = 1;
		}
		else if (i1->value * i1->quantity < i2->value * i2->quantity)
		{
			result = -1;
		}
		break;
	case 5:
		if (i1->weight * i1->quantity > i2->weight * i2->quantity)
		{
			result = 1;
		}
		else if (i1->weight * i1->quantity < i2->weight * i2->quantity)
		{
			result = -1;
		}
		break;
	default:
		break;
	}




	return false;
}

int FitemInv::getId()
{
	return id;
}

FString FitemInv::getDisplayName()
{
	return displayName;
}

float FitemInv::getWeight()
{
	return weight;
}

float FitemInv::getValue()
{
	return value;
}

int FitemInv::getQuantity()
{
	return quantity;
}

float FitemInv::getTotalWeight()
{
	return weight*quantity;
}

float FitemInv::getTotalValue()
{
	return value*quantity;
}

bool FitemInv::Stack(FitemInv * other)
{
	if (id == other->id)
	{
		quantity += other->quantity;
		other = nullptr;
		return true;
	}
	else
	{
		return false;
	}
}

FitemInv FitemInv::getNewItemInv(int id, FString displayName, float weight, float value, int quantity)
{
	return FitemInv(id,displayName,weight,value,quantity);
}



