#include "Neptune.h"

ANeptune::ANeptune()
{
	PrimaryActorTick.bCanEverTick = true;
	SemiMajorAxis = 10100.0f;
	SemiMinorAxis = 9800.0f;
	OrbitSpeed = -5.43f;
	CurrentOrbitAngle = 0.0f;
}

void ANeptune::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANeptune::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewScale =  FVector(4.0f, 4.0f, 4.0f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = 2.70f;

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

