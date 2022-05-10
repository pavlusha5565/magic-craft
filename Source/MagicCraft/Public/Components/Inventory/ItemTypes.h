// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemTypes.generated.h"

UENUM(BlueprintType)
enum class EItemEnum : uint8
{
	None		UMETA(DisplayName = "None"),
	Equipment	UMETA(DisplayName = "Equipment"),
	Poition		UMETA(DisplayName = "Poition"),
	Flower		UMETA(DisplayName = "Flower"),
	Reagent		UMETA(DisplayName = "Reagent"),
	Scrap		UMETA(DisplayName = "Scrap"),
	Ores		UMETA(DisplayName = "Ores"),
	Quest		UMETA(DisplayName = "Quest"),
};

USTRUCT(BlueprintType)
struct FItem : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName ID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Descrtiprion;

	// Item icon
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTexture2D* Thambnail;

	// Type of item.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EItemEnum Type;

	//// Actor to use in inventory
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	//TSubclassOf<class AInventoryItem> InventoryActor;
	//
	//// Mesh to spawned in world
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	//TSubclassOf<class AWorldItem> WorldActor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float DefaultPrice;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 Quantity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 MaxStack;

	FItem()
	{
		ID = FName(TEXT("Item"));
		Name = FName(TEXT("Item"));
		Descrtiprion = FText::FromString(TEXT("Descrtiprion"));
		DefaultPrice = 10.f;
		Type = EItemEnum::None;
		MaxStack = 60;
	}
};