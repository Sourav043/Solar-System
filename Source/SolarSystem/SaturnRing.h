
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SaturnRing.generated.h"

class UProceduralMeshComponent;

UCLASS(config=Game)
class SOLARSYSTEM_API ASaturnRing : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ASaturnRing();
private :
	const int32 NumSegments = 360;
protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMajorAxis;

	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMinorAxis;

	UPROPERTY(EditAnywhere, Category = "Orbit",config)
		float OrbitSpeed;

	float CurrentOrbitAngle;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UProceduralMeshComponent* ProceduralMesh;

	UPROPERTY(EditAnywhere, Category = "Materials")
		UMaterialInterface* TrajectoryMaterial;
	float  OuterRadius;
	float InnerRadius;
	float  Thickness;
	void GenerateHollowEllipseMesh();

};
