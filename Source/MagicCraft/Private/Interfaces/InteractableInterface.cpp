// Personal copyright


#include "Interfaces/InteractableInterface.h"

// Add default functionality here for any IInteractableInterface functions that are not pure virtual.

// Sets default values
IInteractableInterface::IInteractableInterface()
{
}


void IInteractableInterface::Interact_Implementation()
{
}



void IInteractableInterface::InteractRealesed_Implementation()
{
}

void IInteractableInterface::Use_Implementation()
{
}

void IInteractableInterface::FocusItem_Implementation()
{
}


void IInteractableInterface::UnfocusItem_Implementation()
{
}

void IInteractableInterface::OnComponentBeginOverlap_Implementation()
{
}

void IInteractableInterface::OnComponentEndOverlap_Implementation()
{
}

FString IInteractableInterface::GetActionText_Implementation()
{
	TArray<FStringFormatArg> Args;
	Args.Add(FStringFormatArg(Name));
	Args.Add(FStringFormatArg(Action));

	return FString::Format(TEXT("{1} {0}"), Args);
}
