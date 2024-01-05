
#include "SaturnRing.h"
#include "ProceduralMeshComponent.h"
#include "Engine.h"

ASaturnRing::ASaturnRing()
{
	PrimaryActorTick.bCanEverTick = true;

    ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
    RootComponent = ProceduralMesh;

    OuterRadius = 150.0f;
    InnerRadius = 100.0f;
    Thickness = 10.0f;

	SemiMajorAxis = 7800.0f;
	SemiMinorAxis = 7500.0f;
	OrbitSpeed = -9.69f;
	CurrentOrbitAngle = 0.0f;

}

void ASaturnRing::BeginPlay()
{
	Super::BeginPlay();
    GenerateHollowEllipseMesh();
}


void ASaturnRing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewScale = FVector(5.2f, 5.2f, 5.2f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = 100.23f;

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

// Called every frame
void ASaturnRing::GenerateHollowEllipseMesh()
{
    if (ProceduralMesh)
    {
        TArray<FVector> Vertices;
        TArray<int32> Triangles;
        TArray<FVector> Normals;
        TArray<FVector2D> UV0;
        TArray<FProcMeshTangent> Tangents;

        for (int32 i = 0; i <= NumSegments; i++)
        {
            float Angle = 2.0f * PI * static_cast<float>(i) / static_cast<float>(NumSegments);

            FVector OuterVertex = FVector(FMath::Cos(Angle) * OuterRadius, FMath::Sin(Angle) * OuterRadius, 0.0f);
            FVector InnerVertex = FVector(FMath::Cos(Angle) * InnerRadius, FMath::Sin(Angle) * InnerRadius, 0.0f);

            Vertices.Add(OuterVertex);
            Vertices.Add(InnerVertex);

            // Normals and Tangents are set arbitrarily for simplicity.
            Normals.Add(FVector(0.0f, 0.0f, 1.0f));
            Normals.Add(FVector(0.0f, 0.0f, 1.0f));

            Tangents.Add(FProcMeshTangent(1.0f, 0.0f, 0.0f));
            Tangents.Add(FProcMeshTangent(1.0f, 0.0f, 0.0f));

            UV0.Add(FVector2D(static_cast<float>(i) / static_cast<float>(NumSegments), 0.0f));
            UV0.Add(FVector2D(static_cast<float>(i) / static_cast<float>(NumSegments), 1.0f));

            Triangles.Add(i * 2);
            Triangles.Add((i + 1) * 2);
            Triangles.Add(i * 2 + 1);

            Triangles.Add(i * 2 + 1);
            Triangles.Add((i + 1) * 2);
            Triangles.Add((i + 1) * 2 + 1);

            Triangles.Add(i * 2);
            Triangles.Add(i * 2 + 1);
            Triangles.Add((i + 1) * 2 + 1);

            Triangles.Add(i * 2);
            Triangles.Add((i + 1) * 2 + 1);
            Triangles.Add((i + 1) * 2);
        }


        ProceduralMesh->CreateMeshSection(0, Vertices, Triangles, Normals, UV0, TArray<FColor>(), Tangents, true);
        //UMaterial* RingMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Game/SolarSystem_Materials/Textures/8k_saturn_ring_alpha.8k_saturn_ring_alpha"));
        UMaterial* RingMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Game/SolarSystem_Materials/Material/M6_Saturn.M6_Saturn"));
        if (RingMaterial)
        {
            ProceduralMesh->SetMaterial(0, RingMaterial);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Failed to load material for the ring."));
        }
    }
}

