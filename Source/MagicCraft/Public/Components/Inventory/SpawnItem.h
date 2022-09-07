// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/Inventory/Item.h"
#include "Interfaces/InteractableInterface.h"

#include "SpawnItem.generated.h"

UCLASS()
class MAGICCRAFT_API ASpawnItem : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ItemMesh;

public:
	// Sets default values for this actor's properties
	ASpawnItem();

	UPROPERTY(VisibleAnywhere, Category = "Item data")
	FItem Item;
	
	UPROPERTY(EditDefaultsOnly, Category = "Item data")
	FName ItemId;

	UPROPERTY(EditDefaultsOnly, Category = "Item Setting")
	bool IsOverlapCollectable;

	UPROPERTY(EditDefaultsOnly, Category = "Item Setting")
	float CollisionSphereRadius = 150.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetupCollisionSphere();

	void SetupMeshByDataTable();
public:	
	// Called every frame
	// virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation() override;

	virtual void OnComponentBeginOverlap_Implementation() override;

protected:
	UStaticMeshComponent* GetItemMesh() { return ItemMesh; }
};
