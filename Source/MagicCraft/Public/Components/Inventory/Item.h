// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "Item.generated.h"

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName ID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FText Descrtiprion;

	// Item icon
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UTexture2D* Thambnail;

	// Type of item.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	EItemEnum Type;
	
	// Mesh to spawned in world
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMesh* StaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DefaultPrice;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 Quantity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 MaxStack;

	FItem()
	{
		ID = FName(TEXT("None"));
		Name = FName(TEXT("None"));
		Descrtiprion = FText::FromString(TEXT("None"));
		DefaultPrice = 0.f;
		Type = EItemEnum::None;
		Quantity = 0;
		MaxStack = 0;
	}
};

USTRUCT(BlueprintType)
struct FAssetItem : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FItem Item;

	//// Actor to use in inventory
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class AInventoryItem> InventoryActor;

	//// Actor to use in inventory
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class AActor> WorldActor;
};

UCLASS(BlueprintType)
class MAGICCRAFT_API AInventoryItem : public AActor
{
	GENERATED_BODY()

public:
	AInventoryItem();

	UPROPERTY(EditDefaultsOnly)
	FItem Item;

	UFUNCTION(BlueprintCallable)
	void SpawnWorldItem();

	UFUNCTION(BlueprintCallable)
	void TrashItem();

	UFUNCTION(BlueprintCallable)
	virtual void UseItem();
};