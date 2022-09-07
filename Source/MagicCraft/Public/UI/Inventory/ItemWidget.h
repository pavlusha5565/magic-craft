// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Inventory/Item.h"

#include "ItemWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAGICCRAFT_API UItemWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	FItem Item;

	UFUNCTION(BlueprintCallable)
	void DropItem();

	UFUNCTION(BlueprintCallable)
	void UseItem();
};
