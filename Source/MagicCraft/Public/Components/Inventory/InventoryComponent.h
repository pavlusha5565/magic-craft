// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "Components/Inventory/Item.h"

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
	UFUNCTION(BlueprintCallable)
	TArray<FItem> GetInventory();

	UFUNCTION(BlueprintCallable)
	bool Add(FItem Item);

	UFUNCTION(BlueprintCallable)
	int32 GetFreeSpace(int32 MaxStack, FName ID);

	UFUNCTION(BlueprintCallable)
	int32 GetFreeSlots();
	
	UFUNCTION(BlueprintCallable)
	bool Remove(FName ID, int32 Count);

	UFUNCTION(BlueprintCallable)
	int32 CountOfItem(FName ID);
};
