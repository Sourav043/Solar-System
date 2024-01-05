

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "YourUIPanelWidget.generated.h"

/**
 * 
 */
UCLASS()
class SOLARSYSTEM_API UYourUIPanelWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Planet Properties")
		void SetMass(const FText& MassValue);

	UFUNCTION(BlueprintCallable, Category = "Planet Properties")
		void SetVelocity(const FText& VelocityValue);

	UFUNCTION(BlueprintCallable, Category = "Planet Properties")
		void SetDiameter(const FText& DiameterValue);

	UFUNCTION(BlueprintCallable, Category = "Planet Properties")
		void SetDistance(const FText& DistanceValue);

	
};
