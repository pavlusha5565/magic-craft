// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Animation/AnimationAsset.h"

#include "Components/SkeletalMeshComponent.h"

#include "Interfaces/InteractableInterface.h"

#include "BasicTree.generated.h"

UCLASS()
class MAGICCRAFT_API AInteractableTree : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skeletal Mesh", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* TreeMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn Actor", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> Log;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn Actor", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> Stick;

public:	
	// Sets default values for this actor's properties
	AInteractableTree();

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
    UAnimationAsset* Montage;

	UPROPERTY(EditDefaultsOnly, Category = "Default")
	FName Name;
	
	UPROPERTY(EditAnywhere, Category = "Default")
	float Strength = 100.f;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn Setting")
	int32 LogCount = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn Setting")
	int32 StickCount = 6;
	
	UPROPERTY(EditDefaultsOnly, Category = "Spawn Setting")
	float SpawnRange = 150.f;
		
	UPROPERTY(EditDefaultsOnly, Category = "Spawn Setting")
	float SpawnLogOffset = 20.f;
			
	UPROPERTY(EditDefaultsOnly, Category = "Spawn Setting")
	float SpawnStickOffset = 5.f;

	UFUNCTION(BlueprintCallable)
	void LogSpawn();

	UFUNCTION(BlueprintCallable)
	void StickSpawn();

	UFUNCTION(BlueprintCallable)
	void OnChoped();

	UFUNCTION(BlueprintCallable)
	FVector GenerateRandomLocation(float ExtentScale);

	UFUNCTION(BlueprintCallable)
	void Chop(float Force);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Returns FirstPersonCameraComponent subobject **/
	USkeletalMeshComponent* GetTreeMeshComponent() const { return TreeMesh; }
};
