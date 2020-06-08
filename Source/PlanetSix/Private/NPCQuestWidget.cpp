// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCQuestWidget.h"

UNPCQuestWidget::UNPCQuestWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {


}

void UNPCQuestWidget::NativeConstruct() {

	Super::NativeConstruct();

	Accept->OnClicked.AddDynamic(this, &UNPCQuestWidget::AcceptQuest);
	Reject->OnClicked.AddDynamic(this, &UNPCQuestWidget::RejectQuest);

	TextName->Text = QuestData.QuestTitleName;
	TextDescription->Text = QuestData.QuestDescription;

	
}

void UNPCQuestWidget::AcceptQuest()
{

	RemoveFromParent();
/*	if (NPCRef) 
	{
		NPCRef->SpecifiedQuestOFNPC->IsQuestActive = true;
	}*/
	
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("questaccepted"));

}

void UNPCQuestWidget::RejectQuest()
{
	
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("questrejected"));

}

void UNPCQuestWidget::Tick(FGeometry MyGeometry, float InDeltaTime)
{

	

}