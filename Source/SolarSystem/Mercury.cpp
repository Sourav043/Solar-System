#include "Mercury.h"

AMercury::AMercury()
{
	PrimaryActorTick.bCanEverTick = true;
	SemiMajorAxis = 4300.0f;
	SemiMinorAxis = 4000.0f;
	OrbitSpeed = -28.87f;
	CurrentOrbitAngle = 0.0f;
}

void AMercury::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMercury::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewScale = FVector(1.2f,1.2f,1.2f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = 10.83f;

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


