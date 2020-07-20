// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Engine.h"
#include "Components/EditableTextBox.h"
#include "CurrentQuestTracker.generated.h"

/**
 * 
 */
UCLASS()
class PLANETSIX_API UCurrentQuestTracker : public UUserWidget
{
	GENERATED_BODY()
public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Objectives;
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			UTextBlock* Lefttokill;
		
};
