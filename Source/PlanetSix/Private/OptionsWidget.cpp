// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionsWidget.h"
#include "Components/ComboBoxString.h"
#include "Components/Slider.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetTextLibrary.h"
#include "Engine.h"


#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)


UOptionsWidget::UOptionsWidget(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer) 
{



}

void UOptionsWidget::NativeConstruct()
{
	
	ReturnButton->OnClicked.AddDynamic(this, &UOptionsWidget::ReturnMainMenu);
	ShadowSlider->OnValueChanged.AddDynamic(this, &UOptionsWidget::ChangeShadowQuality);
	TextureSlider->OnValueChanged.AddDynamic(this, &UOptionsWidget::ChangeTextureQuality);
	PostSlider->OnValueChanged.AddDynamic(this, &UOptionsWidget::ChangePostQuality);
	ResComboBox->OnSelectionChanged.AddDynamic(this, &UOptionsWidget::ChangeResolution);
}

void UOptionsWidget::ChangeShadowQuality(float Value)
{
	int ClampedValue = FMath::FloorToFloat(Value);
	auto TextedValue = FString("sg.ShadowQuality ");
	TextedValue.Append(FString::FromInt(ClampedValue));
	GetWorld()->Exec(GetWorld(), *TextedValue);
	ShadowStatus->SetText(ChangeStatus(Value));
	print("Changing Shadow Quality", 4);

}

void UOptionsWidget::ChangeTextureQuality(float Value)
{
	int ClampedValue = FMath::FloorToFloat(Value);
	auto TextedValue = FString("sg.TextureQuality ");
	TextedValue.Append(FString::FromInt(ClampedValue));
	GetWorld()->Exec(GetWorld(), *TextedValue);
	TextureStatus->SetText(ChangeStatus(Value));
	print("Changing Texture Quality", 4);

}

void UOptionsWidget::ChangePostQuality(float Value)
{
	int ClampedValue = FMath::FloorToFloat(Value);
	auto TextedValue = FString("sg.PostProcessQuality ");
	TextedValue.Append(FString::FromInt(ClampedValue));
	GetWorld()->Exec(GetWorld(), *TextedValue);
	PostStatus->SetText(ChangeStatus(Value));
	print("Changing Post Process Quality", 4);

}

void UOptionsWidget::ChangeResolution(FString Value , ESelectInfo::Type type)
{
	if (type != ESelectInfo::Type::OnMouseClick) {
		return;
	}

	if (Value == "1920 x 1080") {
		GetWorld()->Exec(GetWorld(), TEXT("r.setRes 1920x1080f"));

		print("Changing Res 1920x1080", 2);
	}

	if (Value == "1280 x 720") {
		GetWorld()->Exec(GetWorld(), TEXT("r.setRes 1280x720f"));

		print("Changing Res 1280x720f", 2);

	}

	if (Value == "858 x 480") {
		GetWorld()->Exec(GetWorld(), TEXT("r.setRes 858x480f"));

		print("Changing Res 858x480", 2);

	}



}

void UOptionsWidget::ReturnMainMenu()
{
	UUserWidget* MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(), RefWidget);
	MainMenuWidget->AddToViewport();
	RemoveFromParent();
}

FText UOptionsWidget::ChangeStatus(float Value)
{
	int ClampedValue = Value;
	switch (ClampedValue) {
		
	case 0:		return FText::FromString("Low"); 
	case 1:		return  FText::FromString("Medium");
	case 2:		return  FText::FromString("High");
	case 3:		return  FText::FromString("Epic");
	default:	return  FText();
	
	
	}
	return FText();
}
