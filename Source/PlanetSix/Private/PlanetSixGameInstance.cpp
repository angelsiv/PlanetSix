// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetSixGameInstance.h"
#include "PlanetSixPlayerState.h"
#include "Skill.h"


#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)


void UPlanetSixGameInstance::SetPlayerInfo(FPlayerInfo info)
{
	PlayerInfo = info;
	ReloadNetwork();
}

//void UPlanetSixGameInstance::SetPlayerSavedInfo(FPlayerSaveData info)
//{
//	PlayerSave = info;
//	print("Saved info name: " + info.SaveName, -1);
//}

FPlayerSaveData UPlanetSixGameInstance::GetPlayerInfoToSave()
{
	FPlayerSaveData SimplifiedPlayerInfo = FPlayerSaveData();
	
	APlanetSixCharacter* Player = Cast<APlanetSixCharacter>(UGameplayStatics::GetPlayerController(GetWorld(),0)->GetPawn());
	 
	if (Player) {
		//Equipped Skills
		for (auto Skill : Player->Class->EquippedSkillsArray) {

			TArray<FName> RNames;
			RNames = SkillDataTable->GetRowNames();
			FString ContextString;
			for (auto& name : RNames) {

				FSkillData* SkillData = SkillDataTable->FindRow<FSkillData>(name, ContextString);
				if (SkillData->SkillClass == Skill) {

					SimplifiedPlayerInfo.EquippedSkills.Add(SkillData->SkillName);

				}

			}

		}
	


	//Attributes

	SimplifiedPlayerInfo.Level = (Player->Attributes->Level.GetCurrentValue());
	SimplifiedPlayerInfo.Experience = (Player->Attributes->Experience.GetCurrentValue());
	

		print("Player found to save", -1);
	}
	else {
		print("No player found", -1);
	
	}

	//QuestsRegistered
	for (auto Quest : PlayerInfo.QuestsRegistered) {
	
		SimplifiedPlayerInfo.QuestsRegistered.Add(Quest.QuestID);
	
	}

	if (PlayerInfo.QuestsRegistered.Num() > 0) {
		SimplifiedPlayerInfo.LastQuestRegisteredName = PlayerInfo.QuestsRegistered[PlayerInfo.QuestsRegistered.Num() - 1].QuestTitleName.ToString();
	}
	//Inventory

	SimplifiedPlayerInfo.InventoryItemsID = PlayerInfo.InventoryItemsID;
	


	return SimplifiedPlayerInfo;

}

FPlayerSaveData UPlanetSixGameInstance::GetPlayerSave()
{
	return PlayerSave;
}

FPlayerInfo UPlanetSixGameInstance::GetPlayerInfo()
{
	return PlayerInfo;
}

FQuestData UPlanetSixGameInstance::GetCurrentQuest()
{
	return PlayerInfo.QuestAccepted;
}

void UPlanetSixGameInstance::ReduceCurrentTargetNumber(int ID)
{
	int32 objectiveNumber = PlayerInfo.QuestAccepted.AtObjectiveNumber;

	if (PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets.Contains(ID)) {

		PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID]--;

		APlanetSixCharacter* Player = Cast<APlanetSixCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		int32 var = PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID];
		Player->CurrentQuestTracker->Lefttokill->SetText(FText::FromString(FString::FromInt(var)));

		if (PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID] <= 0)
		{
			//ObjectiveCompleted
			PlayerInfo.QuestAccepted.objectives[objectiveNumber].IsCompleted = true;
			MoveToNextObjective();
			print("Finished Objective number " + FString::FromInt(objectiveNumber + 1), -1);
			//Success
		}
		ReloadNetwork();
	}
	else {
		print("This is not the right target", -1);
	
	}

}

int UPlanetSixGameInstance::ReduceItemNumber(int ID, int Quantity)
{
	int objectiveNumber = PlayerInfo.QuestAccepted.AtObjectiveNumber;

	if (PlayerInfo.QuestAccepted.objectives[objectiveNumber].Objectivetype == EObjectiveType::Gathering)
	{
		if (PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets.Contains(ID))
		{
			APlanetSixCharacter* Player = Cast<APlanetSixCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
			

			if (PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID] > Quantity)
			{
				PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID] -= Quantity;
				int32 var = PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID];
				Player->CurrentQuestTracker->Lefttokill->SetText(FText::FromString(FString::FromInt(var)));
				print("numbers Left to pick " + FString::FromInt(var), -1);
				return Quantity;
			}
			else
			{
				int quant = PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID];
				PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID] = 0;

				//ObjectiveCompleted
				PlayerInfo.QuestAccepted.objectives[objectiveNumber].IsCompleted = true;
				MoveToNextObjective();
				//Success

				return quant;
			}
		}

	}
	return 0;
}

void UPlanetSixGameInstance::SaveGame()
{
	
	UPlanetSixSaveGame* SavedGame = Cast<UPlanetSixSaveGame>(UGameplayStatics::CreateSaveGameObject(UPlanetSixSaveGame::StaticClass()));
	SavedGame->PlayerInfo = GetPlayerInfoToSave();

	print("Saving in PlayerSave " + PlayerSave.SaveName, -1);

	if (UGameplayStatics::SaveGameToSlot(SavedGame, PlayerSave.SaveName, 0)) {
	
		print("Saved true",-1);
	}

	CreateWidget<UUserWidget>(GetWorld(), SavingEffectWidget)->AddToViewport();
	

}

bool UPlanetSixGameInstance::GetQuestRegistered(FQuestData Quest)
{
	return PlayerInfo.QuestsRegistered.Contains(Quest);
}


void UPlanetSixGameInstance::MoveToNextObjective()
{
	PlayerInfo.QuestAccepted.AtObjectiveNumber++;

	if (PlayerInfo.QuestAccepted.AtObjectiveNumber >= PlayerInfo.QuestAccepted.objectives.Num()) {

		PlayerInfo.QuestAccepted.IsQuestCompleted = true;
		Cast<APlanetSixCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->QuestCompletedWidget->AddToViewport();
		if (PlayerInfo.QuestAccepted.QuestItemReward.getId() != 0) 
		{
		Cast<APlanetSixCharacter>(GetPrimaryPlayerController()->GetPawn())->InventoryComponent->add(PlayerInfo.QuestAccepted.QuestItemReward, 0);
		}

		for (FQuestData q : PlayerInfo.QuestsRegistered) 
		{
			if (q.QuestID == PlayerInfo.QuestAccepted.QuestID) {
				q.IsQuestCompleted = true;
				PlayerInfo.QuestAccepted = FQuestData::Empty();
					break;
			}
		}	
	}
	else 
	{
		int32 y;
		APlanetSixCharacter* Player = Cast<APlanetSixCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if (Player)
		{
			Player->CurrentQuestTracker->Objectives->SetText(PlayerInfo.QuestAccepted.objectives[PlayerInfo.QuestAccepted.AtObjectiveNumber].ObjectiveDescription);

		for  (auto pair : PlayerInfo.QuestAccepted.objectives[PlayerInfo.QuestAccepted.AtObjectiveNumber].Targets)
			{
			y = pair.Key;
			}
			Player->CurrentQuestTracker->Lefttokill->SetText(FText::FromString(FString::FromInt(PlayerInfo.QuestAccepted.objectives[PlayerInfo.QuestAccepted.AtObjectiveNumber].Targets[y])));
			
		}
	}
	ReloadNetwork();
}



void UPlanetSixGameInstance::SetCurrentQuest(FQuestData Quest)
{
	PlayerInfo.QuestAccepted = Quest;
	print("Setting Quest" + PlayerInfo.QuestAccepted.QuestTitleName.ToString(), -1);
	ReloadNetwork();

}

void UPlanetSixGameInstance::AddQuest(FQuestData Quest)
{
	if (!PlayerInfo.QuestsRegistered.Contains(Quest)) {
		
		PlayerInfo.QuestsRegistered.Add(Quest);
		PlayerInfo.QuestsRegistered.Sort([](const FQuestData& a, const FQuestData& b) {return a.QuestID < b.QuestID; });
		ReloadNetwork();
	}
	else {
		print("Quest already registered", -1);
	}
}

void UPlanetSixGameInstance::AddItemsToinventoryplayer(TArray<FItemBaseData> Items)
{
	PlayerInfo.InventoryItemsID.Empty();

	for (int i = 0; i < Items.Num(); i++)
	{
		PlayerInfo.InventoryItemsID.Add(Items[i].getId(), Items[i].getQuantity());
		
	}
}

void UPlanetSixGameInstance::ReloadNetwork()
{
	APlanetSixPlayerState* PlayerState = GetPrimaryPlayerController()->GetPlayerState<APlanetSixPlayerState>();
	PlayerState->ReloadPlayerInfo();

}
