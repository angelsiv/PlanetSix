// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Attributes.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UAttributes : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface to make a character have attributes
 */
class PLANETSIX_API IAttributes
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** enum for attribute names. */
	enum EAttributes {Brawn, Vitality, Agility, Mind, Social, Fate};
	UPROPERTY(Category = MapsAndSets, EditAnywhere)
		TMap<EAttributes, uint32> Attributes;

	uint32 Brawn = 1;
	uint32 Vitality = 1;
	uint32 Agility = 1;
	uint32 Mind = 1;
	uint32 Social = 1;
	uint32 Fate = 1;

	virtual void AddAttributes(EAttributes EAttribute, uint32 Attribute);
	virtual void AddAttributes(EAttributes EAttribute);
	virtual void CreateAttributes();
	virtual void CreateAttributes(uint32 Brawn, uint32 Vitality, uint32 Agility, uint32 Mind, uint32 Social, uint32 Fate);
};
