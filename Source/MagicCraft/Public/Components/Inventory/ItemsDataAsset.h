// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "Components/Inventory/Item.h"

#include "ItemsDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class MAGICCRAFT_API UItemsDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	TArray<FAssetItem> Items;

	UFUNCTION(BlueprintCallable)
	FItem GetItemById(FName Id, bool& IsFound);
	
	UFUNCTION(BlueprintCallable)
	TSubclassOf<AInventoryItem> GetActorById(FName Id, bool& IsFound);
};
