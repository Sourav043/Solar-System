
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Uranus.generated.h"

UCLASS(config = Game)
class SOLARSYSTEM_API AUranus : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AUranus();
	virtual void Tick(float DeltaTime) override;
protected:
	
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMajorAxis;

	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMinorAxis;

	UPROPERTY(EditAnywhere, Category = "Orbit",config)
		float OrbitSpeed;

	float CurrentOrbitAngle;

	

};
