// Pavlusha5565 copyright.


#include "Objects/Items/Ingot.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AIngot::AIngot()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AIngot::BeginPlay()
{
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Root Component"));
	RootComponent = CollisionComponent;
	CollisionComponent->InitSphereRadius(400.f);

	IngotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IngotMesh"));
	IngotMesh->SetupAttachment(RootComponent);

	MaterialDinamic = IngotMesh->CreateAndSetMaterialInstanceDynamic(0);
}

void AIngot::HeatUp(float deltaTemp)
{
	if (deltaTemp > 0) {
		Temperature = Temperature + (deltaTemp * HeatCapacity);
	}
	if (Temperature > MaxTemperature) {
		Temperature = MaxTemperature;
	}
	PrimaryActorTick.SetTickFunctionEnable(true);
	UpdateEmmission();
}

void AIngot::HeatDown(float deltaTemp)
{
	if (deltaTemp > 0) {
		Temperature = Temperature - (deltaTemp * HeatCapacity);
	}
	if (Temperature <= 0) {
		Temperature = 0;
		PrimaryActorTick.SetTickFunctionEnable(false);
	}
	UpdateEmmission();
}

void AIngot::Carry()
{
}

void AIngot::PickUp()
{
}

void AIngot::UpdateEmmission()
{
	float LerpEmmission = FMath::Lerp(0.f, MaxEmmisionStrength, Temperature / MaxTemperature);
	MaterialDinamic->SetScalarParameterValue(EmissiveParamName, LerpEmmission);
}

void AIngot::Tick(float DeltaTime)
{
	HeatDown(DeltaTime);
}

float AIngot::GetTemperature()
{
	return Temperature;
}
