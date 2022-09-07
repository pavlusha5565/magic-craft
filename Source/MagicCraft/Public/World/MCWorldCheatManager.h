// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "MCWorldCheatManager.generated.h"

/**
 * 
 */
UCLASS()
class MAGICCRAFT_API UMCWorldCheatManager : public UCheatManager
{
	GENERATED_BODY()
	
public:
	UFUNCTION(exec)
	void GetTimeOfDay();
	
	UFUNCTION(exec)
	void GetDays();

protected:
};
