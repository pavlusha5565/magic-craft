// Pavlusha5565 copyright.


#include "Components/Inventory/InventoryComponent.h"

FName NULL_NAME = FName(TEXT("Null"));

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	InventorySlotLimit = 12;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

TArray<FItem> UInventoryComponent::GetInventory()
{
	return Inventory;
}

bool UInventoryComponent::Add(FItem Item)
{
	if (GetFreeSpace(Item.MaxStack, Item.ID) < Item.Quantity) {
		return false;
	}

	TArray<int32> Indexes;

	for (int i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i].ID == Item.ID)
		{
			Indexes.Add(i);
		}
	}

	if (Indexes.Num() == 0) {
		if (Inventory.Num() < InventorySlotLimit)
		{
			Inventory.Add(Item);
			return true;
		}
		return false;
	}
	else {
		int32 Total = Item.Quantity;

		for (int32 i = 0; i < Indexes.Num(); i++)
		{
			int32 index = Indexes[i];

			int32 MaxStack = Inventory[index].MaxStack;

			//  оличество добавл€емого > оставшегос€ места
			if (Total <= MaxStack - Inventory[index].Quantity)
			{
				Inventory[index].Quantity += Item.Quantity;
				Total = 0;
			}
			else {
				Inventory[index].Quantity = MaxStack;
				Total -= MaxStack - Inventory[index].Quantity;
			}
		}

		if (Total > 0) {
			FItem NewSlotItem = Item;
			NewSlotItem.Quantity = 0;
			Inventory.Add(NewSlotItem);

			FItem AddItem = Item;
			AddItem.Quantity = Total;
			Add(AddItem);
			return true;
		}
	}
	return false;
}

int32 UInventoryComponent::GetFreeSpace(int32 MaxStack, FName ID)
{
	int32 FreeSpaceQuantity = 0;
	if (ID != NULL_NAME) {
		for (int i = 0; i < Inventory.Num(); i++)
		{
			if (Inventory[i].ID == ID
				&& Inventory[i].Quantity < Inventory[i].MaxStack)
			{

				FreeSpaceQuantity += Inventory[i].MaxStack - Inventory[i].Quantity;
			}
		}
	}

	if (InventorySlotLimit > Inventory.Num()) 
	{
		FreeSpaceQuantity += GetFreeSlots() * MaxStack;
	}

	return FreeSpaceQuantity;
}

int32 UInventoryComponent::GetFreeSlots()
{
	return InventorySlotLimit - Inventory.Num();
}

bool UInventoryComponent::Remove(FName ID, int32 Count)
{
	int32 total = Count;

	for (int i = Inventory.Num() - 1; i >= 0; i--)
	{
		if (Inventory[i].ID == ID)
		{
			if (total >= Inventory[i].Quantity)
			{
				total -= Inventory[i].Quantity;
				Inventory.RemoveAt(i);
			}
			else
			{
				Inventory[i].Quantity -= total;
				total = 0;
			}

			if (total == 0)
			{
				break;
			}
		}
	}
	return total == 0;
}

int32 UInventoryComponent::CountOfItem(FName ID)
{
	int32 total = 0;
	for (int i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i].ID == ID)
		{

			total += Inventory[i].Quantity;
		}
	}
	return total;
}