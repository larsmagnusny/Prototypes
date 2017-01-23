// Fill out your copyright notice in the Description page of Project Settings.

#include "Protopuzzle.h"
#include "ButtonController.h"


// Sets default values for this component's properties
UButtonController::UButtonController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UButtonController::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UButtonController::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

