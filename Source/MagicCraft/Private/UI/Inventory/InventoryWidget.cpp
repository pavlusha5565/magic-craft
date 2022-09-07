// Pavlusha5565 copyright.


#include "UI/Inventory/InventoryWidget.h"
#include "Player/MCPlayerController.h"


void UInventoryWidget::UpdateItems()
{
	AMCPlayerController* PController = Cast<AMCPlayerController>(GetWorld()->GetFirstPlayerController());
	if (!PController) { return; }

	Items = PController->GetInventoryComponent()->GetInventory();
}

void UInventoryWidget::UpdateInventory_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("UpdateInventory_Implementation"));
}
