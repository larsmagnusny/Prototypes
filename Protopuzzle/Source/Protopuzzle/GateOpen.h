// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "ButtonController.h"
#include "GateOpen.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROTOPUZZLE_API UGateOpen : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGateOpen();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UPROPERTY(EditAnywhere)
		AActor* PressurePlate;

	UPROPERTY(EditAnywhere)
		float RaiseAmount = 500.0f;

	UPROPERTY(EditAnywhere)
		float RaiseSpeed = 200.0f;
private:
	UButtonController* ButtonController;
	FVector OriginalPosition;
};
