// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <Widget/ReservedForcesGameplayWidget.h>
#include <InputMappingContext.h>
#include "ReservedForcesPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AReservedForcesPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnEndGameCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UInputMappingContext> ReservedForcesMappingContext;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> GameplayWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> ResultWidget;
};
