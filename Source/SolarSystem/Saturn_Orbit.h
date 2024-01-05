
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Saturn_Orbit.generated.h"

class UProceduralMeshComponent;

UCLASS()
class SOLARSYSTEM_API ASaturn_Orbit : public AActor
{
	GENERATED_BODY()
	
public:	

	ASaturn_Orbit();

private:
	const int32 NumSegments = 360;
protected:
	
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UProceduralMeshComponent* ProceduralMeshComponent;

	UPROPERTY(EditAnywhere, Category = "Materials")
		UMaterialInterface* TrajectoryMaterial;

	void GenerateHollowEllipseMesh();

};
