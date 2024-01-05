
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sun.generated.h"

UCLASS()
class SOLARSYSTEM_API ASun : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ASun();
	virtual void Tick(float DeltaTime) override;
protected:
	
	virtual void BeginPlay() override;

};
