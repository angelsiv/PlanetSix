// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionsWidget.h"
#include "Components/ComboBoxString.h"
#include "Components/Slider.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetTextLibrary.h"
#include "GameFramework/GameUserSettings.h"
#include "Engine.h"


#define print(text, i) if (GEngine) GEngine->AddOnScreenDebugMessage(i, 1.5, FColor::White,text)


UOptionsWidget::UOptionsWidget(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{



}

void UOptionsWidget::NativeConstruct()
{
	//Assigning functions to events
	ReturnButton->OnClicked.AddDynamic(this, &UOptionsWidget::Return);
	ShadowSlider->OnValueChanged.AddDynamic(this, &UOptionsWidget::ChangeShadowQuality);
	TextureSlider->OnValueChanged.AddDynamic(this, &UOptionsWidget::ChangeTextureQuality);
	PostSlider->OnValueChanged.AddDynamic(this, &UOptionsWidget::ChangePostQuality);
	ResComboBox->OnSelectionChanged.AddDynamic(this, &UOptionsWidget::ChangeResolution);

	//Retrieving UserSettings
	UserSettings = UGameUserSettings::GetGameUserSettings();

	//Setting retrieved values to Widget
	ShadowSlider->SetValue(UserSettings->GetShadowQuality());
	TextureSlider->SetValue(UserSettings->GetTextureQuality());
	PostSlider->SetValue(UserSettings->GetPostProcessingQuality());

	ShadowStatus->SetText(ChangeStatus(UserSettings->GetShadowQuality()));
	TextureStatus->SetText(ChangeStatus(UserSettings->GetTextureQuality()));
	PostStatus->SetText(ChangeStatus(UserSettings->GetPostProcessingQuality()));
	//
	EWindowMode::Type WindowMode = UserSettings->GetDefaultWindowMode();
	switch (WindowMode) {
	case EWindowMode::Fullscreen:			ScreenType = "f";	print("Fullscreen", -1); break;
	case EWindowMode::Windowed:				ScreenType = "w";	print("Windowed", -1);  break;
	case EWindowMode::WindowedFullscreen:	ScreenType = "wf";	print("WindowedFullscreen", -1);  break;
	default:break;

	}
}

void UOptionsWidget::ChangeShadowQuality(float Value)
{
	int ClampedValue = FMath::FloorToFloat(Value);
	auto TextedValue = FString("sg.ShadowQuality ");
	TextedValue.Append(FString::FromInt(ClampedValue));
	if (GetWorld()->Exec(GetWorld(), *TextedValue)) {
		print("True", -1);

	}
	else {
		print(TextedValue, -1);
	}
	ShadowStatus->SetText(ChangeStatus(Value));
	print("Changing Shadow Quality", 4);

}

void UOptionsWidget::ChangeTextureQuality(float Value)
{
	int ClampedValue = FMath::FloorToFloat(Value);
	auto TextedValue = FString("sg.TextureQuality ");
	TextedValue.Append(FString::FromInt(ClampedValue));
	if (GetWorld()->Exec(GetWorld(), *TextedValue)) {
		print("True", -1);

	}
	else {
		print(TextedValue, -1);
	}
	TextureStatus->SetText(ChangeStatus(Value));
	print("Changing Texture Quality", 4);

}

void UOptionsWidget::ChangePostQuality(float Value)
{
	int ClampedValue = FMath::FloorToFloat(Value);
	auto TextedValue = FString("sg.PostProcessQuality ");
	TextedValue.Append(FString::FromInt(ClampedValue));
	if (GetWorld()->Exec(GetWorld(), *TextedValue)) {
		print("True", -1);

	}
	else {
		print(TextedValue, -1);
	}
	PostStatus->SetText(ChangeStatus(Value));
	print("Changing Post Process Quality", 4);

}

void UOptionsWidget::ChangeResolution(FString Value, ESelectInfo::Type type)
{
	if (type != ESelectInfo::Type::OnMouseClick) {
		return;
	}
	FString Command = TEXT("r.SetRes ");

	if (Value == "1920 x 1080") {

		Command.Append("1920x1080");
		Command.Append(ScreenType);
		if (GetWorld()->Exec(GetWorld(), *Command)) {
			print("True", -1);

		}
		else {
			print(Command, -1);
		}
		print("Changing Res 1920x1080", 2);
		return;
	}

	if (Value == "1280 x 720") {

		Command.Append("1280 x 720");
		Command.Append(ScreenType);
		if (GetWorld()->Exec(GetWorld(), *Command)) {
			print("True", -1);

		}
		else {
			print(Command, -1);

		}
		print("Changing Res 1280x720", 2);
		return;

	}

	if (Value == "858 x 480") {
		Command.Append("858x480");
		Command.Append(ScreenType);
		if (GetWorld()->Exec(GetWorld(), *Command)) {
			print("True", -1);

		}
		else {
			print(Command, -1);
		}
		print("Changing Res 858x480", 2);
		return;

	}



}

void UOptionsWidget::Return()
{
	UUserWidget* ReturnWidget = CreateWidget<UUserWidget>(GetWorld(), RefWidget);
	if (RefWidget != nullptr)
	{
		ReturnWidget->AddToViewport();
		RemoveFromParent();
	}
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
