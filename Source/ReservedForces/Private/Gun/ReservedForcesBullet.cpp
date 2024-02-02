// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/ReservedForcesBullet.h"

// Sets default values
AReservedForcesBullet::AReservedForcesBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AReservedForcesBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReservedForcesBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

