// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ingot.generated.h"

UCLASS()
class MAGICCRAFT_API AIngot : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* IngotMesh;

public:	
	// Sets default values for this actor's properties
	AIngot();

	UPROPERTY(EditDefaultsOnly, Category = "Item")
	FName ItemId = FName("None");

	UPROPERTY(EditDefaultsOnly, Category = "Item")
	FName IngotName = FName("Ingot");

	void HeatUp(float deltaTemp);
	void HeatDown(float deltaTemp);
	void Carry();
	void PickUp();
	void UpdateEmmission();

	float GetTemperature();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class UMaterialInstanceDynamic* MaterialDinamic;

	UPROPERTY(EditDefaultsOnly, Category = "Temperature")
	float Temperature = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Temperature")
	float MaxTemperature = 200.f;

	UPROPERTY(EditDefaultsOnly, Category = "Temperature")
	float HeatCapacity = 1.f;

	UPROPERTY(EditDefaultsOnly, Category = "Material")
	FName EmissiveParamName;

	UPROPERTY(EditDefaultsOnly, Category = "Material")
	float EmmisionStrength = 1.f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Material")
	float MaxEmmisionStrength = 3.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UStaticMeshComponent* GetIngotMesh() { return IngotMesh; }
};
