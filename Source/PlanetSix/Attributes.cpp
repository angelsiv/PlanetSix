// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes.h"

// Add default functionality here for any IAttributes functions that are not pure virtual.

/** Overload 1 : add +x to the attribute selected
* be careful not to change the attribute to something smaller than what it was
*/
void IAttributes::AddAttributes(EAttributes EAttribute, uint32 Attribute) //TODO make it impossible to reduce the attribute smaller than what it was
{
	Attributes.Emplace(EAttribute, Attribute);
}

/** Overload 2 : add +1 to the attribute selected */
void IAttributes::AddAttributes(EAttributes EAttribute)
{
	Attributes.Emplace(EAttribute, Attributes[EAttribute]++);
}

/** Make attributes for a character for example */
void IAttributes::CreateAttributes()
{
	Attributes.Add(EAttributes::Brawn, Brawn);
	Attributes.Add(EAttributes::Vitality, Vitality);
	Attributes.Add(EAttributes::Agility, Agility);
	Attributes.Add(EAttributes::Mind, Mind);
	Attributes.Add(EAttributes::Social, Social);
	Attributes.Add(EAttributes::Fate, Fate);
}

/** Make attributes depending on defined attributes */
void IAttributes::CreateAttributes(uint32 Brawn, uint32 Vitality, uint32 Agility, uint32 Mind, uint32 Social, uint32 Fate)
{
	Attributes.Add(EAttributes::Brawn, Brawn);
	Attributes.Add(EAttributes::Vitality, Vitality);
	Attributes.Add(EAttributes::Agility, Agility);
	Attributes.Add(EAttributes::Mind, Mind);
	Attributes.Add(EAttributes::Social, Social);
	Attributes.Add(EAttributes::Fate, Fate);
}