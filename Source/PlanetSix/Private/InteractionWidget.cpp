// This work is the sole property of 2Pow6 Games.


#include "InteractionWidget.h"
#include "Components/TextBlock.h"
#include "PlanetSixCharacter.h"


void UInteractionWidget::NativeConstruct()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UInteractionWidget::SetInteractionText(FText InteractText)
{
	InteractionText->SetText(InteractText);
}
