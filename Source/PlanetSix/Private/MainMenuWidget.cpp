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

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameAndUI());
}

void UMainMenuWidget::StartGame()
{
	print("Start Game", -1);
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;

	UGameplayStatics::OpenLevel(this, "NetworkTestMenu");
	
}

void UMainMenuWidget::OpenOptions()
{
	UUserWidget* OptionsWidget = CreateWidget<UUserWidget>(GetWorld(),RefWidget);
	OptionsWidget->AddToViewport();
	RemoveFromParent();
	
	print("OpenOptions", -1);

}

void UMainMenuWidget::ExitGame()
{
	UKismetSystemLibrary::QuitGame(this,GetWorld()->GetFirstPlayerController(),TEnumAsByte<EQuitPreference::Type>(),false);
	print("Exit Game", -1);

}
