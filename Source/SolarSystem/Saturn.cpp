#include "Saturn.h"

ASaturn::ASaturn()
{
	PrimaryActorTick.bCanEverTick = true;
	SemiMajorAxis = 7800.0f;
	SemiMinorAxis = 7500.0f;
	OrbitSpeed = -9.69f;
	CurrentOrbitAngle = 0.0f;
}

void ASaturn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASaturn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewScale = FVector(5.2f, 5.2f, 5.2f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = 10.23f;

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
