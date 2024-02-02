// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/ReservedForcesCharacter.h"
#include <GameFramework/CharacterMovementComponent.h>
#include <Kismet/GameplayStatics.h>
#include <EnhancedInputComponent.h>

// Sets default values
AReservedForcesCharacter::AReservedForcesCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShadowBodyCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ShadowBodyCPP"));
	if (ShadowBodyCPP) {
		ShadowBodyCPP->SetupAttachment(RootComponent);

		WeaponInBackCPP = CreateDefaultSubobject<UChildActorComponent>(TEXT("WeaponInBackCPP"));
		if (WeaponInBackCPP) {
			WeaponInBackCPP->SetupAttachment(ShadowBodyCPP);
		}
	}

	LowerBodyCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LowerBodyCPP"));
	if (LowerBodyCPP) {
		LowerBodyCPP->SetupAttachment(RootComponent);
	}

	CameraCPP = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraCPP"));
	if (CameraCPP) {
		CameraCPP->SetupAttachment(RootComponent);

		FirstPersonCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonCPP"));
		if (FirstPersonCPP) {
			FirstPersonCPP->SetupAttachment(CameraCPP);

			WeaponInHandCPP = CreateDefaultSubobject<UChildActorComponent>(TEXT("WeaponInHandCPP"));
			if (WeaponInHandCPP) {
				WeaponInHandCPP->SetupAttachment(FirstPersonCPP);
			}
		}
	}
}

float AReservedForcesCharacter::GetSpeedCPP() const
{
	return GetVelocity().Length();
}

bool AReservedForcesCharacter::CanRunCPP() const
{
	return (MoveForwardValueCPP > 0.0) && isRunPressedCPP;
}

void AReservedForcesCharacter::TickRunCPP()
{
	if (CanRunCPP()) {
		switch (StateCPP) 
		{
		case StateOfCharacterCPP::Idle:
			StateCPP = StateOfCharacterCPP::Running;
			GetCharacterMovement()->MaxWalkSpeed *= 2;
		}
	}
	else {
		switch (StateCPP) 
		{
		case StateOfCharacterCPP::Running:
			StateCPP = StateOfCharacterCPP::Idle;
			GetCharacterMovement()->MaxWalkSpeed *= 0.5;
		}
	}
}

void AReservedForcesCharacter::OnFootstepLCPP()
{
	UGameplayStatics::PlaySoundAtLocation(this, FootstepLSoundCPP, LowerBodyCPP->GetSocketLocation("foot_l"));
}

void AReservedForcesCharacter::OnFootstepRCPP()
{
	UGameplayStatics::PlaySoundAtLocation(this, FootstepLSoundCPP, LowerBodyCPP->GetSocketLocation("foot_r"));
}

// Called when the game starts or when spawned
void AReservedForcesCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AReservedForcesCharacter::OnTriggerRun(const FInputActionValue& Value)
{
	isRunPressedCPP = Value.Get<bool>();
}

// Called every frame
void AReservedForcesCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AReservedForcesCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent * EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		EnhancedInputComponent->BindAction(RunInputAction, ETriggerEvent::Triggered, this, &AReservedForcesCharacter::OnTriggerRun);
	}
}

