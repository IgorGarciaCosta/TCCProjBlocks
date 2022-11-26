// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Grippables/GrippableStaticMeshActor.h"
#include "GrippableBlock.generated.h"

/**
 * 
 */
UCLASS()
class VREXPANSIONPLUGIN_API AGrippableBlock : public AGrippableStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AGrippableBlock(const FObjectInitializer& ObjectInitializer);

public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector StartLocation;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FRotator StartRotation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float TraceDistance = 40.f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString ActorNameOpt1 = "SkeletalMeshComponent0";
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString ActorNameOpt2 = "GraspingHand_C_1";
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bTouchedTarget = false;
	UPROPERTY(BlueprintReadOnly)
		bool bTouchedPreviousState = false;

	UFUNCTION(BlueprintCallable)
		void MakeTrace();
	UFUNCTION(BlueprintImplementableEvent)
		void TriggerSensorObjectIn();
	UFUNCTION(BlueprintImplementableEvent)
		void TriggerSensorObjectOut();
};
