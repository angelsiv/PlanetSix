// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 *
 */

class UButton;
class UEditableTextBox;

UCLASS()
class PLANETSIX_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StartButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* OptionsButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* ExitButton;
	

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> RefOptionWidget;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> RefStartGameWidget;

public:
	UMainMenuWidget(const FObjectInitializer& ObjectInitializer);

	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
		void StartGame();

	UFUNCTION(BlueprintCallable)
		void OpenOptions();

	UFUNCTION(BlueprintCallable)
		void ExitGame();



};
