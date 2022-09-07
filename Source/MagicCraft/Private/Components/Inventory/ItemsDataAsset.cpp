// Pavlusha5565 copyright.

#include "Components/Inventory/ItemsDataAsset.h"

FItem UItemsDataAsset::GetItemById(FName Id, bool& IsFound)
{
	for (int32 i = 0; i < Items.Num(); i++)
	{
		if (Items[i].Item.ID == Id) {
			IsFound = true;
			return Items[i].Item;
		}
	}
	IsFound = false;
	return FItem();
}

TSubclassOf<AInventoryItem> UItemsDataAsset::GetActorById(FName Id, bool& IsFound)
{
	for (int32 i = 0; i < Items.Num(); i++)
	{
		if (Items[i].Item.ID == Id) {
			IsFound = true;
			return Items[i].InventoryActor;
		}
	}
	IsFound = false;
	return NULL;
}
