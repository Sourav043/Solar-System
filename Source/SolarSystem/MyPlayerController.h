
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "YourUIPanelWidget.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SOLARSYSTEM_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:

    AMyPlayerController();
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
        TSubclassOf<class UUserWidget> WidgetClass;

    UFUNCTION(BlueprintCallable, Category = "UI")
        void ShowWidget(FString mass, FString velocity, FString diameter, double distance);

    UFUNCTION(BlueprintCallable, Category = "UI")
        void StopWidget();

    UPROPERTY()
        UYourUIPanelWidget* WidgetInstance;
    UFUNCTION()
        void PerformRaycast();
    
    virtual void SetupInputComponent() override;

    /** Mapping context used for pawn control. */
    UPROPERTY()
        class UInputMappingContext* PawnMappingContext;

    
    UPROPERTY()
        class UInputAction* MoveAction;

    UPROPERTY()
        class UInputAction* StopAction;
    AActor* HitActor;
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
};
