// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TouchFloorDetector.generated.h"

UCLASS()
class VREXPANSIONPLUGIN_API ATouchFloorDetector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATouchFloorDetector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Custom Cpp Params")
		class UBoxComponent* DetectorBox;

private:

	UFUNCTION()
		void FloorHit(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
