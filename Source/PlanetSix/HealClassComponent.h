// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ClassComponent.h"
#include "HealClassComponent.generated.h"

/**
 * 
 */
UCLASS()
class PLANETSIX_API UHealClassComponent : public UClassComponent
{
	GENERATED_BODY()
	
public:
	UHealClassComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
