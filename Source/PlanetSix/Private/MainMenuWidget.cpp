// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/MainMenuWidget.h"
#include "Engine.h"
#include "Components/CanvasPanel.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)

UMainMenuWidget::UMainMenuWidget(const FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer){


}

void UMainMenuWidget::NativeConstruct() {
	Super::NativeConstruct();

	StartButton->OnClicked.AddDynamic(this, &UMainMenuWidget::StartGame);
	OptionsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OpenOptions);
	ExitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::ExitGame);


}

void UMainMenuWidget::StartGame()
{
	print("Start Game", -1);
	UGameplayStatics::OpenLevel(this, "ThirdPersonExampleMap");
}

void UMainMenuWidget::OpenOptions()
{

	print("OpenOptions", -1);

}

void UMainMenuWidget::ExitGame()
{
	UKismetSystemLibrary::QuitGame(this,GetWorld()->GetFirstPlayerController(),TEnumAsByte<EQuitPreference::Type>(),false);
	print("Exit Game", -1);

}
