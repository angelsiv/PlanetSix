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

void UPlanetSixGameInstance::SetPlayerSavedInfo(FPlayerSaveData info)
{
	PlayerSave = info;
}

FPlayerSaveData UPlanetSixGameInstance::GetPlayerInfoToSave()
{
	FPlayerSaveData SimplifiedPlayerInfo = FPlayerSaveData();
	
	APlanetSixCharacter* Player = Cast<APlanetSixCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	 
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
	}


	//Attributes
	SimplifiedPlayerInfo.Attributes.Add(Player->Attributes->ArmorsProficiency.GetBaseValue());
	SimplifiedPlayerInfo.Attributes.Add(Player->Attributes->WeaponsProficiency.GetBaseValue());
	SimplifiedPlayerInfo.Attributes.Add(Player->Attributes->AbilitiesProficiency.GetBaseValue());
	SimplifiedPlayerInfo.Attributes.Add(Player->Attributes->Level.GetBaseValue());
	SimplifiedPlayerInfo.Attributes.Add(Player->Attributes->Experience.GetBaseValue());
	SimplifiedPlayerInfo.Attributes.Add(Player->Attributes->Health.GetBaseValue());
	SimplifiedPlayerInfo.Attributes.Add(Player->Attributes->Shield.GetBaseValue());
	SimplifiedPlayerInfo.Attributes.Add(Player->Attributes->ArmorReduction.GetBaseValue());
	SimplifiedPlayerInfo.Attributes.Add(Player->Attributes->WeaponDamage.GetBaseValue());
	SimplifiedPlayerInfo.Attributes.Add(Player->Attributes->AbilityDamage.GetBaseValue());



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
		print("Targets reduced by one", -1);
		ReloadNetwork();
		if (PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID] <= 0)
		{

			//ObjectiveCompleted
			PlayerInfo.QuestAccepted.objectives[objectiveNumber].IsCompleted = true;
			MoveToNextObjective();
			print("Finished Objective number " + FString::FromInt(objectiveNumber + 1), -1);
			//Success
		}
	}
	else {
		print("This is not the right target", -1);
	
	}
}

int UPlanetSixGameInstance::ReduceItemNumber(int ID, int Quantity)
{
	//UPlanetSixGameInstance* GameInstance = Cast<UPlanetSixGameInstance>(GetGameInstance());
	int objectiveNumber = PlayerInfo.QuestAccepted.AtObjectiveNumber;

	if (PlayerInfo.QuestAccepted.objectives[objectiveNumber].Objectivetype == EObjectiveType::Gathering)
	{
		if (PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets.Contains(ID))
		{

			if (PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID] > Quantity)
			{
				PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID] -= Quantity;
				return Quantity;
			}
			else
			{
				int quant = PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID];
				PlayerInfo.QuestAccepted.objectives[objectiveNumber].Targets[ID] = 0;


				//ObjectiveCompleted
				PlayerInfo.QuestAccepted.objectives[objectiveNumber].IsCompleted = true;
				MoveToNextObjective();
				print("Finished Objective number " + FString::FromInt(objectiveNumber + 1), -1);
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
		//auto gameinstance = Cast<UPlanetSixGameInstance>(GetGameInstance());
		//int objectiveNumber = gameinstance->GetCurrentQuest().AtObjectiveNumber;
		//Cast<APlanetSixCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->InventoryComponent->RemoveQuestItem(PlayerInfo.QuestAccepted.objectives[]);
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
