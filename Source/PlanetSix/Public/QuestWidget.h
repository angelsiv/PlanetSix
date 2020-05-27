// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLANETSIX_API UQuestWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta =(BindWidget))
		FText titleWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		FText WidgetQuestDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		FText ObjectivesQuest;



};
