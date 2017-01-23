// Fill out your copyright notice in the Description page of Project Settings.

#include "Protopuzzle.h"
#include "ButtonController.h"

#include "Components/SkeletalMeshComponent.h"


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
	
	if (!trigger)
	{
		UE_LOG(LogTemp, Error, TEXT("TriggerVolume for this button has not been assigned!"))
	}
}


// Called every frame
void UButtonController::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (!trigger)
		return;

	TArray<AActor*> OverlappingActors;

	trigger->GetOverlappingActors(OverlappingActors);

	if (OverlappingActors.Num() > 0)
	{
		for (AActor* actor : OverlappingActors)
		{
			UE_LOG(LogTemp, Warning, TEXT("Overlapping: %s"), *actor->GetName());
		}

		PressDown = true;
	}
	else {
		PressDown = false;
	}

	USkeletalMeshComponent* SkeletalComponent = Cast<USkeletalMeshComponent>(GetOwner()->GetComponentByClass(USkeletalMeshComponent::StaticClass()));

	if (!SkeletalComponent) {
		UE_LOG(LogTemp, Error, TEXT("FAILED!"));
		return;
	}

	if (PressDown && !SkeletalComponent->IsPlaying())
	{
		//UE_LOG(LogTemp, Warning, TEXT("PLAYING ANIMATION"));
		SkeletalComponent->SetPlayRate(1.0f);
		SkeletalComponent->Play(false);
	}
	else if(!PressDown && !SkeletalComponent->IsPlaying()){
		UE_LOG(LogTemp, Warning, TEXT("PLAYING ANIMATION Backwards!"));
		SkeletalComponent->SetPlayRate(-1.0f);
		SkeletalComponent->Play(false);
	}
	
}
void UButtonController::OnBeginOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) 
{

}


