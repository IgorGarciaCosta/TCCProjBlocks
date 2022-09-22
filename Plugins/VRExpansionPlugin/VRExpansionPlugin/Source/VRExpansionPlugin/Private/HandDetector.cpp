// Fill out your copyright notice in the Description page of Project Settings.


#include "HandDetector.h"
#include "DrawDebugHelpers.h"
#include "Components/SceneComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UHandDetector::UHandDetector()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHandDetector::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHandDetector::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//FVector Start = GetOwner()->GetActorLocation();//GetComponentLocation();
	//FVector End = Start + GetOwner()->GetActorForwardVector() * TraceDistance;//GetForwardVector() * TraceDistance;
	//DrawDebugLine(GetWorld(), Start, End, FColor::Red);
}

