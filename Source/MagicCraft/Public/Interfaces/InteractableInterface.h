// Personal copyright

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MAGICCRAFT_API IInteractableInterface
{
	GENERATED_BODY()
	// Sets default values for this actor's properties
public:
	IInteractableInterface();

	FString Name;

	FString Action;

	// Action to interact
	UFUNCTION(BlueprintNativeEvent)
	void Interact();
	virtual void Interact_Implementation();
	
	// Action release button interact
	UFUNCTION(BlueprintNativeEvent)
	void InteractRealesed();
	virtual void InteractRealesed_Implementation();

	// Action release button interact
	UFUNCTION(BlueprintNativeEvent)
	void Use();
	virtual void Use_Implementation();

	// Action watch at item
	UFUNCTION(BlueprintNativeEvent)
	void FocusItem();
	virtual void FocusItem_Implementation();

	// Action watch out at item
	UFUNCTION(BlueprintNativeEvent)
	void UnfocusItem();
	virtual void UnfocusItem_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void OnComponentBeginOverlap();
	virtual void OnComponentBeginOverlap_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void OnComponentEndOverlap();
	virtual void OnComponentEndOverlap_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Info")
	FString GetActionText();
	virtual FString GetActionText_Implementation();
};
