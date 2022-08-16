// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"

#include "Components/Inventory/ItemsDataAsset.h"

#include "MCGameState.generated.h"

/**
 * 
 */
UCLASS()
class MAGICCRAFT_API AMCGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	AMCGameState();

	UPROPERTY(EditAnywhere)
	UItemsDataAsset* ItemsDataAsset;
};
