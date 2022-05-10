// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "Components/Inventory/InventoryComponent.h"

#include "MCPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MAGICCRAFT_API AMCPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UInventoryComponent* Inventory;
};
