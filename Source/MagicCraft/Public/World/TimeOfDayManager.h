// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeOfDayManager.generated.h"

UCLASS()
class MAGICCRAFT_API ATimeOfDayManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeOfDayManager();

	UPROPERTY(EditAnywhere)
	float SunriseTimeMark = 8.f;

	UPROPERTY(EditAnywhere)
	float SunsetTimeMark = 18.f;

	/* Apply offset(seconds) to change time of day */
	UPROPERTY(EditDefaultsOnly)
	float HourOffset = 0.f;
	/* Apply offset to change days gone number */
	UPROPERTY(EditDefaultsOnly)
	int32 DayOffset = 0;

	/* Scale real second in to game second */
	UPROPERTY(EditAnywhere)
	float TimeScale = 10.f;

	UFUNCTION(BlueprintCallable)
	void UpdateTimeOfDay(float DeltaTime);
	
	UFUNCTION(BlueprintCallable)
	bool GetIsNight();

	UFUNCTION(BlueprintCallable)
	int32 GetHour();

	UFUNCTION(BlueprintCallable)
	float GetTime();

	UFUNCTION(BlueprintCallable)
	int32 GetMinutes();

	UFUNCTION(BlueprintCallable)
	int32 GetDays();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float Time = 0;
	int32 Days = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
