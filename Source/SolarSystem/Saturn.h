
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Saturn.generated.h"

UCLASS(config = Game)
class SOLARSYSTEM_API ASaturn : public AActor
{
	GENERATED_BODY()
	
public:	
	ASaturn();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMajorAxis;

	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMinorAxis;

	UPROPERTY(EditAnywhere, Category = "Orbit" , config)
		float OrbitSpeed;

	float CurrentOrbitAngle;


};
