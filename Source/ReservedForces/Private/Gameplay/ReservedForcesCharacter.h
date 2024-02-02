// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Camera/CameraComponent.h>
#include <InputAction.h>
#include "ReservedForcesCharacter.generated.h"

UENUM(BlueprintType)
enum class StateOfCharacterCPP : uint8
{
	Idle,
	Aiming,
	Reloading,
	Swapping,
	Running,
};

UCLASS()
class AReservedForcesCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AReservedForcesCharacter();

	UFUNCTION(BlueprintCallable)
	virtual float GetSpeedCPP() const;

	UFUNCTION(BlueprintCallable)
	virtual bool CanRunCPP() const;

	UFUNCTION(BlueprintCallable)
	virtual void TickRunCPP();

	UFUNCTION(BlueprintCallable)
	virtual void OnFootstepLCPP();

	UFUNCTION(BlueprintCallable)
	virtual void OnFootstepRCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnTriggerRun(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
	StateOfCharacterCPP StateCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
	bool isRunPressedCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
	float MoveForwardValueCPP;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USoundBase> FootstepLSoundCPP;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USoundBase> FootstepRSoundCPP;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInputAction> RunInputAction;


private:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> ShadowBodyCPP; 

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UChildActorComponent> WeaponInBackCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> LowerBodyCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> CameraCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> FirstPersonCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UChildActorComponent> WeaponInHandCPP;

};
