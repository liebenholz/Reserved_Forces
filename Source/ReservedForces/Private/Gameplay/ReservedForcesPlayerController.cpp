// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/ReservedForcesPlayerController.h"
#include <EnhancedInputSubsystems.h>
#include <Kismet/GameplayStatics.h>
#include "ReservedForcesGameMode.h"

void AReservedForcesPlayerController::OnEndGameCPP()
{
	UUserWidget* Widget = CreateWidget(this,ResultWidget);
	if (Widget) {
		Widget->AddToViewport();
	}
}

// Called when the game starts or when spawned
void AReservedForcesPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem) {
		Subsystem->AddMappingContext(ReservedForcesMappingContext, 0);
	}

	UUserWidget* Widget = CreateWidget(this, GameplayWidget);
	if (Widget) {
		Widget->AddToViewport();
	}

	AReservedForcesGameMode* GameMode = Cast<AReservedForcesGameMode>(UGameplayStatics::GetGameMode(this));
	if (GameMode) {
		GameMode->OnEndGameCPP.AddUniqueDynamic(this, &AReservedForcesPlayerController::OnEndGameCPP);
	}
}
