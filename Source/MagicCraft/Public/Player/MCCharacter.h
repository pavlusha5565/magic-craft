// Pavlusha5565 copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "MCCharacter.generated.h"

class UCameraComponent;

UCLASS(config = Game)
class MAGICCRAFT_API AMCCharacter : public ACharacter
{
	GENERATED_BODY()
	
	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;

public:
	// Sets default values for this character's properties
	AMCCharacter();

	float ArmLength;

	AActor* FocusedItem;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	void PrimaryAttack();

	FHitResult TraceLine(float Distance);

	void BeginInterract();

	void EndInterract();

	void ChechInteractable(float Distance);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetCameraComponent() const { return CameraComponent; }
};
