// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionsWidget.h"
#include "Components/ComboBoxString.h"
#include "Components/Slider.h"
#include "Components/Button.h"



UOptionsWidget::UOptionsWidget(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer) 
{



}

void UOptionsWidget::NativeConstruct()
{
	
	ReturnButton->OnClicked.AddDynamic(this, &UOptionsWidget::ReturnMainMenu);

}

void UOptionsWidget::ChangeShadowQuality(int level)
{
}

void UOptionsWidget::ChangeTextureQuality(int level)
{
}

void UOptionsWidget::ChangePostQuality(int level)
{
}

void UOptionsWidget::ChangeResolution(int level)
{
}

void UOptionsWidget::ReturnMainMenu()
{
	UUserWidget* MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(), RefWidget);
	MainMenuWidget->AddToViewport();
	RemoveFromParent();
}
