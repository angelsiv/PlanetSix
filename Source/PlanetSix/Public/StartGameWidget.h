// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLANETSIX_API UStartGameWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UStartGameWidget(const FObjectInitializer& ObjectInitializer);
	
	void NativeConstruct() override;
};
