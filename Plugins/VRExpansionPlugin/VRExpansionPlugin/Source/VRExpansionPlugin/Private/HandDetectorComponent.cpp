// Fill out your copyright notice in the Description page of Project Settings.


#include "HandDetectorComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/SceneComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "Delegates/Delegate.h"
#include "Grippables/GrippableStaticMeshActor.h"

// Sets default values for this component's properties
UHandDetectorComponent::UHandDetectorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHandDetectorComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT(" message"));
	// ...
	
}


// Called every frame
void UHandDetectorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//UE_LOG(LogTemp, Warning, TEXT("Your message"));

	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * TraceDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);
	FHitResult HitResult;
	bool HastHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECollisionChannel::ECC_WorldDynamic
	);
	if (HastHit) {
		AActor* Target = HitResult.GetActor();
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *Target->GetName());
		if (Target->GetName() == ActorNameOpt1 || Target->GetName() == ActorNameOpt2) {
			bTouchedTarget = true;
			if (bTouchedPreviousState == false) {
				bTouchedPreviousState = true;
				AGrippableStaticMeshActor* BlockActor = Cast<AGrippableStaticMeshActor>(GetOwner());
				//UE_LOG(LogTemp, Warning, TEXT("Your message"));
				BlockActor->TriggerBlockEvent();
			}
		}
		else {
			bTouchedTarget = false;
			if (bTouchedPreviousState == true) {
				bTouchedPreviousState = false;
			}
		}
	}
	else {
		bTouchedTarget = false;
		if (bTouchedPreviousState == true) {
			bTouchedPreviousState = false;
		}
	}

	
}

