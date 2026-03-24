// Fill out your copyright notice in the Description page of Project Settings.


#include "ClassBase.h"

// Sets default values
AClassBase::AClassBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AClassBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClassBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AClassBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

