// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/SlateEnums.h"
#include "OptionsWidget.generated.h"

/**
 * 
 */
class UComboBoxString;
class USlider;
class UTextBlock;
class UButton;
class UGameUserSettings;

UCLASS()
class PLANETSIX_API UOptionsWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//Option menu components
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		USlider* ShadowSlider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* ShadowStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		USlider* TextureSlider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* TextureStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		USlider* PostSlider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* PostStatus;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UComboBoxString* ResComboBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* ReturnButton;

	//Ref to MainMenu for the return button
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> RefWidget;


public:
	UOptionsWidget(const FObjectInitializer& ObjectInitializer);

	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
		void ChangeShadowQuality(float Value);

	UFUNCTION(BlueprintCallable)
		void ChangeTextureQuality(float Value);

	UFUNCTION(BlueprintCallable)
		void ChangePostQuality(float Value);
	
	UFUNCTION(BlueprintCallable)
		void ChangeResolution(FString Value, ESelectInfo::Type type);
	
	UFUNCTION(BlueprintCallable)
		void ReturnMainMenu();
private:
	FText ChangeStatus(float Value);

	FString ScreenType = "w";
	UGameUserSettings* UserSettings;
};

