// Pavlusha5565 copyright.


#include "World/TimeOfDayManager.h"

// sec 60s
// min 60s * 60m = 3600
// day 60s * 60m * 24h = 86400

int32 secondInDay = 86400;
int32 secondInHour = 3600;

// Sets default values
ATimeOfDayManager::ATimeOfDayManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATimeOfDayManager::UpdateTimeOfDay(float DeltaTime)
{
	float dilatedTime = DeltaTime * TimeScale * GetWorldSettings()->GetActorTimeDilation();

	Time += dilatedTime;
	if (Time > secondInDay) {
		Time -= secondInDay;
		Days += 1;
	}
}

bool ATimeOfDayManager::GetIsNight()
{
	float hour = this->GetTime() / this->GetHour();
	if (hour > SunsetTimeMark && hour < SunriseTimeMark) {
		return true;
	}
	return false;
}

int32 ATimeOfDayManager::GetHour()
{
	int32 hours = this->GetTime() / secondInHour;
	return hours;
}

float ATimeOfDayManager::GetTime()
{
	return Time;
}

int32 ATimeOfDayManager::GetMinutes()
{
	int32 hour = this->GetHour();
	int32 minutes = (this->GetTime() / 60) - (hour * 60);
	return minutes;
}

int32 ATimeOfDayManager::GetDays()
{
	return Days;
}

// Called when the game starts or when spawned
void ATimeOfDayManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimeOfDayManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->UpdateTimeOfDay(DeltaTime);
}

