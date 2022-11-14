// Fill out your copyright notice in the Description page of Project Settings.


#include "Grippables/GrippableBlock.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"



AGrippableBlock::AGrippableBlock(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGrippableBlock::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	StartRotation = GetActorRotation();
}

void AGrippableBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

void AGrippableBlock::MakeTrace()
{
	//UE_LOG(LogTemp, Warning, TEXT("Your message"));
	FVector Start = GetActorLocation();
	FVector End = Start + GetActorUpVector() * TraceDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);
	FHitResult HitResult;
	bool HastHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECollisionChannel::ECC_WorldDynamic
	);
	if (HastHit) {
		UPrimitiveComponent* Target = HitResult.GetComponent();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Target->GetName());
		if (Target->GetName() == ActorNameOpt1 || Target->GetName() == ActorNameOpt2) {
			bTouchedTarget = true;
			if (bTouchedPreviousState == false) {
				bTouchedPreviousState = true;
				//AGrippableStaticMeshActor* BlockActor = Cast<AGrippableStaticMeshActor>(GetOwner());
				//UE_LOG(LogTemp, Warning, TEXT("HAND"));
				//BlockActor->TriggerBlockEvent();
				TriggerSensorObjectIn();
			}
		}
		else {
			/*bTouchedTarget = false;
			if (bTouchedPreviousState == true) {
				bTouchedPreviousState = false;
			}*/
		}
	}
	else {
		bTouchedTarget = false;
		if (bTouchedPreviousState == true) {
			bTouchedPreviousState = false;
			TriggerSensorObjectOut();
		}
	}
}
