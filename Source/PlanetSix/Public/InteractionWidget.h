// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class PLANETSIX_API UInteractionWidget : public UUserWidget
{
	GENERATED_BODY()

public:
		UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
			UTextBlock* InteractionText;
public:

	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
		void SetInteractionText(FText InteractText);
};
