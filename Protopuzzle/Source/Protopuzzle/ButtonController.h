// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TriggerVolume.h"
//
#include "Components/ActorComponent.h"
#include "ButtonController.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROTOPUZZLE_API UButtonController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UButtonController();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* trigger = nullptr;

	void OnBeginOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

private:
	bool PressDown = false;
	
};
