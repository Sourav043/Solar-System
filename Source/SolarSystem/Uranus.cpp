#include "Uranus.h"

AUranus::AUranus()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SemiMajorAxis = 9100.0f;
	SemiMinorAxis = 8800.0f;
	OrbitSpeed = -6.81f;
	CurrentOrbitAngle = 0.0f;
}

// Called when the game starts or when spawned
void AUranus::BeginPlay()
{
	Super::BeginPlay();
	
}

void AUranus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewScale = FVector(4.7f, 4.7f, 4.7f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = -2.76f;

	NewRotation.Roll += RotationSpeed * DeltaTime;

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

