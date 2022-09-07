// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "UI/Inventory/ItemWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/Inventory/Item.h"

#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAGICCRAFT_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, meta = ( BindWidget ) )
	class UUniformGridPanel* GridPanel;

	UPROPERTY(BlueprintReadWrite)
	TArray<FItem> Items;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void UpdateInventory();
	void UpdateInventory_Implementation();

	UFUNCTION(BlueprintCallable)
	void UpdateItems();
};
