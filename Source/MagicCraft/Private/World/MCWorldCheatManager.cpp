// Pavlusha5565 copyright.


#include "World/MCWorldCheatManager.h"

#include "World/MCGameState.h"

void UMCWorldCheatManager::GetTimeOfDay()
{
    AMCGameState* GameState = Cast<AMCGameState>(GetWorld()->GetGameState());
    check(GameState);

    TArray<FStringFormatArg> arg;
}

void UMCWorldCheatManager::GetDays()
{
    AMCGameState* GameState = Cast<AMCGameState>(GetWorld()->GetGameState());
    check(GameState);

    TArray<FStringFormatArg> arg;
}
