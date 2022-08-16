// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "MCCharacter.generated.h"

UCLASS(config = Game)
class MAGICCRAFT_API AMCCharacter : public ACharacter
{
	GENERATED_BODY()
	
	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/** Collision Sphere */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* CollisionSphere;

public:
	// Sets default values for this character's properties
	AMCCharacter();

	float ArmLength;

	AActor* FocusedItem;

	UPROPERTY()
	TSubclassOf<AActor> Weapon;

	UPROPERTY(EditAnywhere)
	bool IsSprint;

	UFUNCTION(BlueprintCallable)
	FHitResult TraceLine(float Distance);

	UFUNCTION(BlueprintCallable)
	void Sprint();

	UFUNCTION(BlueprintCallable)
	void StopSprinting();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	void PrimaryAttack();


	void BeginInterract();

	void EndInterract();

	void ChechInteractable(float Distance);

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& Hit
	);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetCameraComponent() const { return CameraComponent; }
};
