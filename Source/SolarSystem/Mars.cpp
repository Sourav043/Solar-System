
#include "Mars.h"

AMars::AMars()
{
	PrimaryActorTick.bCanEverTick = true;

	SemiMajorAxis = 5800.0f;
	SemiMinorAxis = 5500.0f;
	OrbitSpeed = -14.08f;
	CurrentOrbitAngle = 0.0f;
}

void AMars::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMars::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewScale = FVector(1.6f, 1.6f, 1.6f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = 0.24f;

	NewRotation.Yaw += RotationSpeed * DeltaTime;

	SetActorRotation(NewRotation);

	const FVector NewLocation = FVector(
		SemiMajorAxis * FMath::Cos(FMath::DegreesToRadians(CurrentOrbitAngle)),
		SemiMinorAxis * FMath::Sin(FMath::DegreesToRadians(CurrentOrbitAngle)),
		GetActorLocation().Z
	);

	SetActorLocation(NewLocation);

	CurrentOrbitAngle += OrbitSpeed * DeltaTime;
	if (CurrentOrbitAngle >= 360.0f)
	{
		CurrentOrbitAngle = 0.0f;
	}

}
