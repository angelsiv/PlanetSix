// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCQuestWidget.h"

#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::Orange,text)

UNPCQuestWidget::UNPCQuestWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {


}

void UNPCQuestWidget::NativeConstruct() {

	Super::NativeConstruct();

	Accept->OnClicked.AddDynamic(this, &UNPCQuestWidget::AcceptQuest);
	Reject->OnClicked.AddDynamic(this, &UNPCQuestWidget::RejectQuest);
	
	

	
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


void UNPCQuestWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	TextName->SetText(QuestData.QuestTitleName);
	TextDescription->SetText( QuestData.QuestDescription);
	print("Printing " + QuestData.QuestTitleName.ToString(), 9);
	

}