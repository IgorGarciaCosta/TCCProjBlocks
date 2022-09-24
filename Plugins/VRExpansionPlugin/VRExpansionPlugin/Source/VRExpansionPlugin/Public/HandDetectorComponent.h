// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "HandDetectorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VREXPANSIONPLUGIN_API UHandDetectorComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHandDetectorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	UPROPERTY(EditAnywhere)
		float TraceDistance = 30.f;
	UPROPERTY(EditAnywhere)
		FString ActorNameOpt1 = "GraspingHand_C_0";
	UPROPERTY(EditAnywhere)
		FString ActorNameOpt2 = "GraspingHand_C_1";
	UPROPERTY(EditAnywhere)
		bool bTouchedTarget = false;
	UPROPERTY()
		bool bTouchedPreviousState = false;
};
