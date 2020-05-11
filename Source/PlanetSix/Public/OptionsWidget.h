// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OptionsWidget.generated.h"

/**
 * 
 */
class UComboBoxString;
class USlider;
class UTextBlock;
class UButton;

UCLASS()
class PLANETSIX_API UOptionsWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		USlider* ShadowSlider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* ShadowText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		USlider* TextureSlider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* TextureText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		USlider* PostSlider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* PostText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UComboBoxString* ResComboBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* ReturnButton;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> RefWidget;

public:
	UOptionsWidget(const FObjectInitializer& ObjectInitializer);

	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
		void ChangeShadowQuality(int level);

	UFUNCTION(BlueprintCallable)
		void ChangeTextureQuality(int level);

	UFUNCTION(BlueprintCallable)
		void ChangePostQuality(int level);
	
	UFUNCTION(BlueprintCallable)
		void ChangeResolution(int level);
	
	UFUNCTION(BlueprintCallable)
		void ReturnMainMenu();


};

