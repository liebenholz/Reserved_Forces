// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ReservedForcesGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FReservedForcesGameModeOnEndGame, AReservedForcesGameMode, OnEndGameCPP);

/**
 * 
 */
UCLASS()
class AReservedForcesGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateRankingCPP();

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FReservedForcesGameModeOnEndGame OnEndGameCPP;

protected:
	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)
	FDateTime StartTimeCPP;

	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)
	FDateTime EndTimeCPP;

	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)
	TArray<int32> RankingScoresCPP;

	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)
	TArray<FString> RankingTimesCPP;

	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)
	int32 RankingCPP;

	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)
	int32 ScoreCPP;
};
