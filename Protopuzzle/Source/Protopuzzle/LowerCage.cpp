// Fill out your copyright notice in the Description page of Project Settings.

#include "Protopuzzle.h"
#include "LowerCage.h"


// Sets default values for this component's properties
ULowerCage::ULowerCage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULowerCage::BeginPlay()
{
	Super::BeginPlay();

	// Get a reference to the pressure plate...
	if (PressurePlate)
	{
		ButtonController = Cast<UButtonController>(PressurePlate->GetComponentByClass(UButtonController::StaticClass()));

		if (!ButtonController)
		{
			UE_LOG(LogTemp, Error, TEXT("No controller Script assigned to: "), *PressurePlate->GetName());
		}
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No PressurePlate Assigned to: %S"), *GetOwner()->GetName());
	}

	OriginalPosition = GetOwner()->GetActorLocation();
}


// Called every frame
void ULowerCage::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (!ButtonController)
		return;

	if (ButtonController->GetPressDown())
	{
		FVector curPosition = GetOwner()->GetActorLocation();

		if (OriginalPosition.Z - curPosition.Z < LowerAmount)
		{
			curPosition.Z -= LowerSpeed*DeltaTime;
			GetOwner()->SetActorLocation(curPosition);
		}
		else {
			curPosition.Z = OriginalPosition.Z - LowerAmount;
			GetOwner()->SetActorLocation(curPosition);
		}
	}
	else
	{
		FVector curPosition = GetOwner()->GetActorLocation();

		if (curPosition.Z < OriginalPosition.Z)
		{
			curPosition.Z += LowerSpeed*DeltaTime;
			GetOwner()->SetActorLocation(curPosition);
		}
		else {
			curPosition.Z = OriginalPosition.Z;
			GetOwner()->SetActorLocation(curPosition);
		}
	}
}

