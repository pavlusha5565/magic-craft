// Pavlusha5565 copyright.


#include "Components/Inventory/SpawnItem.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "World/MCGameState.h"

#include "Player/MCPlayerController.h"

// Sets default values
ASpawnItem::ASpawnItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void ASpawnItem::BeginPlay()
{
	Super::BeginPlay();
	
	AMCGameState* GameState = Cast<AMCGameState>(GetWorld()->GetGameState());
	UE_LOG(LogTemp, Display, TEXT(" GameState search "), *ItemId.ToString());

	check(GameState->ItemsDataAsset)
	UE_LOG(LogTemp, Display, TEXT(" GameState "), *ItemId.ToString());
	bool IsFound = false;
	Item = GameState->ItemsDataAsset->GetItemById(ItemId, IsFound);

	if (!IsFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Item %s has not found. Check SpawnItem and ItemsDataAsset"), *ItemId.ToString());
	}

	if (!ItemMesh->GetStaticMesh())
	{
		UE_LOG(LogTemp, Display, TEXT("Create Static Mesh"));
		SetupMeshByDataTable();
	}

	if (IsOverlapCollectable)
	{
		SetupCollisionSphere();
	}
}


// Called every frame
//void ASpawnItem::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void ASpawnItem::SetupCollisionSphere()
{
	USphereComponent* SphereComponent = NewObject<USphereComponent>(this);
	SphereComponent->SetupAttachment(RootComponent);
	SphereComponent->SetSphereRadius(CollisionSphereRadius);
	SphereComponent->SetGenerateOverlapEvents(true);
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

void ASpawnItem::SetupMeshByDataTable()
{
	check(Item.WorldMesh);
	ItemMesh->SetStaticMesh(Item.WorldMesh);
	ItemMesh->SetSimulatePhysics(true);
}

void ASpawnItem::Interact_Implementation()
{
	AMCPlayerController* PController = Cast<AMCPlayerController>(GetWorld()->GetFirstPlayerController());
	if (!PController) { return; }

	UInventoryComponent* Inventory = PController->GetInventoryComponent();
	bool IsAdded = Inventory->Add(Item);
	if (IsAdded)
	{
		Destroy();
	}
}

void ASpawnItem::OnComponentBeginOverlap_Implementation()
{
	AMCPlayerController* PController = Cast<AMCPlayerController>(GetWorld()->GetFirstPlayerController());
	if (!PController) { return; }

	UInventoryComponent* Inventory = PController->GetInventoryComponent();
	bool IsAdded = Inventory->Add(Item);
	if (IsAdded)
	{
		Destroy();
	}
}

