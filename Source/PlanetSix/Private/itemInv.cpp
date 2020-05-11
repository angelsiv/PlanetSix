// Fill out your copyright notice in the Description page of Project Settings.


#include "itemInv.h"
#include "Item_base.h"
#include "ItemInv.h"

// Sets default values for this component's properties
//UitemInv::UitemInv() : id(), displayName(), weight(), value(), quantity()
//{
//
//}
UitemInv::UitemInv(int Id, FString DisplayName, float Weight, float Value, int Quantity): id(), displayName(),  weight(),  value(),  quantity()
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

int UitemInv::compare(UitemInv * i1, UitemInv * i2, int type)
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

int UitemInv::getId()
{
	return id;
}

FString UitemInv::getDisplayName()
{
	return displayName;
}

float UitemInv::getWeight()
{
	return weight;
}

float UitemInv::getValue()
{
	return value;
}

int UitemInv::getQuantity()
{
	return quantity;
}

float UitemInv::getTotalWeight()
{
	return weight*quantity;
}

float UitemInv::getTotalValue()
{
	return value*quantity;
}

bool UitemInv::Stack(UitemInv * other)
{
	if (id == other->id)
	{
		quantity += other->quantity;
		DestructItem(other);
		return true;
	}
	else
	{
		return false;
	}
}

//UitemInv UitemInv::getNewItemInv(int id, FString displayName, float weight, float value, int quantity)
//{
//	return UitemInv(id,displayName,weight,value,quantity);
//}



