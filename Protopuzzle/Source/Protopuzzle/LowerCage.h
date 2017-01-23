// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ButtonController.h"
#include "Components/ActorComponent.h"
#include "LowerCage.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROTOPUZZLE_API ULowerCage : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULowerCage();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UPROPERTY(EditAnywhere)
	AActor* PressurePlate;

	UPROPERTY(EditAnywhere)
	float LowerAmount = 500.0f;

	UPROPERTY(EditAnywhere)
	float LowerSpeed = 200.0f;
private:
	UButtonController* ButtonController;
	FVector OriginalPosition;
};
