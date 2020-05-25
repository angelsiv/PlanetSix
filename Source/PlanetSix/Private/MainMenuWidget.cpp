// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Engine.h"
#include "Components/CanvasPanel.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "PlanetSixSaveGame.h"
#include "PlanetSixGameInstance.h"
#include "PlanetSixPlayerState.h"
#include "Kismet/KismetSystemLibrary.h"

#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)

UMainMenuWidget::UMainMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {


}

void UMainMenuWidget::NativeConstruct() {
	Super::NativeConstruct();

	StartButton->OnClicked.AddDynamic(this, &UMainMenuWidget::StartGame);
	OptionsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OpenOptions);
	ExitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::ExitGame);
	NameReceiverButton->OnClicked.AddDynamic(this, &UMainMenuWidget::EnterName);

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
}

void UMainMenuWidget::StartGame()
{
	print("Start Game", -1);

	UPlanetSixSaveGame* SavedGame = Cast<UPlanetSixSaveGame>(UGameplayStatics::LoadGameFromSlot("Test", 0));

	//If Inputed name doesnt exist
	if (Cast<UPlanetSixGameInstance>(GetGameInstance())->UserName == "") {
		if (SavedGame) {
			//If Saved game
			Cast<UPlanetSixGameInstance>(GetGameInstance())->UserName = SavedGame->UserName;
			Cast<APlanetSixPlayerState>(GetOwningPlayer()->PlayerState)->ChangeName(Cast<UPlanetSixGameInstance>(GetGameInstance())->UserName);

			print(Cast<APlanetSixPlayerState>(GetOwningPlayer()->PlayerState)->UserName + " has been registered", -1);

		}
	}
	else {
		if (GetOwningPlayer()) {


			Cast<APlanetSixPlayerState>(GetOwningPlayer()->PlayerState)->ChangeName(Cast<UPlanetSixGameInstance>(GetGameInstance())->UserName);
			print(Cast<APlanetSixPlayerState>(GetOwningPlayer()->PlayerState)->UserName + " has been registered", -1);
		}
		else {
		
			print("Kaboom", -1);
		}
	}
	


	UUserWidget* StartGameWidget = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), RefStartGameWidget);
	StartGameWidget->AddToViewport();
	RemoveFromParent();
}

void UMainMenuWidget::OpenOptions()
{
	UUserWidget* OptionsWidget = CreateWidget<UUserWidget>(GetWorld(), RefOptionWidget);
	OptionsWidget->AddToViewport();
	RemoveFromParent();

	print("OpenOptions", -1);

}

void UMainMenuWidget::ExitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetWorld()->GetFirstPlayerController(), TEnumAsByte<EQuitPreference::Type>(), false);
	print("Exit Game", -1);

}

void UMainMenuWidget::EnterName()
{
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());

	UPlanetSixGameInstance* PSGameInstance = Cast<UPlanetSixGameInstance>(GameInstance);

	PSGameInstance->UserName = NameReceiverTextBox->GetText().ToString();

	print("Entered name: " + PSGameInstance->UserName, -1);
}