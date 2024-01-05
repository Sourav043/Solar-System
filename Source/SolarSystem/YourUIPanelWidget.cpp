

#include "YourUIPanelWidget.h"

#include <Components/TextBlock.h>

void UYourUIPanelWidget::SetMass(const FText& MassValue)
{
	UTextBlock* MassTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("MassText")));
	if (MassTextBlock)
	{
		MassTextBlock->SetText(MassValue);
	}
}

void UYourUIPanelWidget::SetVelocity(const FText& VelocityValue)
{
	UTextBlock* VelocityTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("VelocityText")));
	if (VelocityTextBlock)
	{
		VelocityTextBlock->SetText(VelocityValue);
	}
}

void UYourUIPanelWidget::SetDiameter(const FText& DiameterValue)
{
	UTextBlock* DiameterTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("DiameterText")));
	if (DiameterTextBlock)
	{
		DiameterTextBlock->SetText(DiameterValue);
	}
}

void UYourUIPanelWidget::SetDistance(const FText& DistanceValue)
{
	UTextBlock* DistanceTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("DistanceText")));
	if (DistanceTextBlock)
	{
		DistanceTextBlock->SetText(DistanceValue);
	}
}
