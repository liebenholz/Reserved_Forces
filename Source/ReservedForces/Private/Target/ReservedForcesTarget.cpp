// Fill out your copyright notice in the Description page of Project Settings.


#include "Target/ReservedForcesTarget.h"

// Sets default values
AReservedForcesTarget::AReservedForcesTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AReservedForcesTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReservedForcesTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

