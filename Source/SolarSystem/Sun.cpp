
#include "Sun.h"

ASun::ASun()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASun::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector EarthScale = FVector(25.0f, 25.0f, 25.0f); 
	RootComponent->SetWorldScale3D(EarthScale);
}

