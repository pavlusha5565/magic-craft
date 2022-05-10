// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "Components/Inventory/ItemTypes.h"

#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAGICCRAFT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TArray<FItem> Inventory;
	int32 InventorySlotLimit;

public:	
	UFUNCTION()
	TArray<FItem> GetInventory();

	UFUNCTION()
	bool Add(FItem Item);

	UFUNCTION()
	int32 GetFreeSpace(int32 MaxStack, FName ID);

	UFUNCTION()
	int32 GetFreeSlots();
	
	UFUNCTION()
	bool Remove(FName ID, int32 Count);

	UFUNCTION()
	int32 CountOfItem(FName ID);
};
