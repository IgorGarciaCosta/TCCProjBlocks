// Fill out your copyright notice in the Description page of Project Settings.


#include "TouchFloorDetector.h"
#include "Components/BoxComponent.h"
#include "Grippables/GrippableBlock.h"

// Sets default values
ATouchFloorDetector::ATouchFloorDetector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DetectorBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DetectorBox"));
	DetectorBox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
	DetectorBox->SetupAttachment(RootComponent);
	

}

// Called when the game starts or when spawned
void ATouchFloorDetector::BeginPlay()
{
	Super::BeginPlay();
	DetectorBox->OnComponentBeginOverlap.AddDynamic(this, &ATouchFloorDetector::FloorHit);

	
}

void ATouchFloorDetector::FloorHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AGrippableBlock* Block = Cast<AGrippableBlock>(OtherActor);

	// O IsValid() verifica se o objeto é != nullptr e se está pendente de destruição, é mais seguro de utilizar para UObjects
	if (IsValid(Block)) {
		Block->SetActorLocation(Block->StartLocation);
		Block->SetActorRotation(Block->StartRotation);
	}
}



