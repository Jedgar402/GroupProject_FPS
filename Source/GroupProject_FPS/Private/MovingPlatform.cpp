// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values for this component's properties
UMovingPlatform::UMovingPlatform()
{
	// Set this component to be initialized when the game starts
	PrimaryComponentTick.bCanEverTick = true;
}

void UMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// Store the initial location of the platform
	InitialLocation = GetOwner()->GetActorLocation();

	// Set the target height relative to the initial location
	TargetHeight += InitialLocation.Z;

	// Set the current location to the initial location
	CurrentLocation = InitialLocation;
}

void UMovingPlatform::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Move the platform up and down
	MovePlatform(DeltaTime);
}

void UMovingPlatform::MovePlatform(float DeltaTime)
{
	// Check if the platform has reached the top or bottom
	if (CurrentLocation.Z >= TargetHeight || CurrentLocation.Z <= InitialLocation.Z)
	{
		// Change the direction of movement
		MoveSpeed *= -1;
	}

	// Update the current location based on the movement direction
	CurrentLocation.Z += MoveSpeed * DeltaTime;

	// Set the new location
	GetOwner()->SetActorLocation(CurrentLocation);
}
