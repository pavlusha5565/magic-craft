// Pavlusha5565 copyright.


#include "Player/MCPlayerController.h"

#include "World/MCWorldCheatManager.h"

AMCPlayerController::AMCPlayerController()
{
	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
	CheatClass = UMCWorldCheatManager::StaticClass();
}

UInventoryComponent* AMCPlayerController::GetInventoryComponent()
{
	return Inventory; 
}
