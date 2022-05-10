// Pavlusha5565 copyright.

#include "Objects/Trees/BasicTree.h"

#include "Components/SphereComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"

#include "DrawDebugHelpers.h"


// Sets default values
AInteractableTree::AInteractableTree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TreeMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	RootComponent = TreeMesh;
}

// Called when the game starts or when spawned
void AInteractableTree::BeginPlay()
{
	Super::BeginPlay();

	Name = FName(TEXT("Дерево"));
}

FVector AInteractableTree::GenerateRandomLocation(float ExtentScale)
{
	FVector Location = RootComponent->GetComponentLocation();
	FVector Extent = FVector(ExtentScale, ExtentScale, ExtentScale);

	FHitResult HitResult;
	FVector SpawnPoint = UKismetMathLibrary::RandomPointInBoundingBox(Location, Extent);

	FVector EndTrace = SpawnPoint;
	SpawnPoint.Z = SpawnPoint.Z + ExtentScale;
	EndTrace.Z = EndTrace.Z - ExtentScale;

	FCollisionObjectQueryParams QueryObjectsParams;
	// QueryObjectsParams = FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllObjects);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	bool isGroundPen = GetWorld()->LineTraceSingleByObjectType(HitResult, SpawnPoint, EndTrace, QueryObjectsParams, QueryParams);

	if (isGroundPen) {
		return HitResult.ImpactPoint;
	}
	else {
		return SpawnPoint;
	}
}

void AInteractableTree::LogSpawn()
{
	check(Log);
	FRotator SpawnRotator(0, 0, FMath::RandRange(0, 15));
	FActorSpawnParameters SpawnInfo;

	for (int32 i = 0; i < LogCount; i++)
	{
		FVector SpawnPoint = AInteractableTree::GenerateRandomLocation(SpawnRange);
		SpawnPoint.Z = SpawnPoint.Z + SpawnLogOffset;
		GetWorld()->SpawnActor<AActor>(Log, SpawnPoint, SpawnRotator, SpawnInfo);
	}
}

void AInteractableTree::StickSpawn()
{
	check(Stick);
	FRotator SpawnRotator(0, 0, FMath::RandRange(0, 15));
	FActorSpawnParameters SpawnInfo;

	for (int32 i = 0; i < StickCount; i++)
	{
		FVector SpawnPoint = AInteractableTree::GenerateRandomLocation(SpawnRange);
		SpawnPoint.Z = SpawnPoint.Z + SpawnStickOffset;
		GetWorld()->SpawnActor<AActor>(Stick, SpawnPoint, SpawnRotator, SpawnInfo);
	}
}

void AInteractableTree::OnChoped()
{
	LogSpawn();
	StickSpawn();

	Destroy();
}

void AInteractableTree::Chop(float Force)
{
	Strength = Strength - Force;
	UE_LOG(LogTemp, Warning, TEXT("CUT %f"), Strength);
	if (Strength < 0) {
		OnChoped();
	}
}
