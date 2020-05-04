// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Blueprint/UserWidget.h"
#include "NPCDialogueWidget.generated.h"

class UButton;




UCLASS()
class PLANETSIX_API UNPCDialogueWidget : public UUserWidget
{


	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		UButton* ButtonComponent;

	


};
