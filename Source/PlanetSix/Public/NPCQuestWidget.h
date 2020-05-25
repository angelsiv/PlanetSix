// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestActor.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Blueprint/UserWidget.h"
#include "Engine.h"
#include "Components/CanvasPanel.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "NPCQuestWidget.generated.h"


class UButton;


UCLASS()
class PLANETSIX_API UNPCQuestWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
     UButton* Accept;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Reject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		FText TextDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		FText TextName;

	FObjectiveData data;



public:

	UNPCQuestWidget(const FObjectInitializer& ObjectInitializer);

	void NativeConstruct() override;


	UFUNCTION(BlueprintCallable)
		void AcceptQuest();

	UFUNCTION(BlueprintCallable)
		void RejectQuest();
	
};
