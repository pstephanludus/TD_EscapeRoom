// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGravityProject.h"
#include "Room1_OpenDoor.h"


// Sets default values for this component's properties
URoom1_OpenDoor::URoom1_OpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URoom1_OpenDoor::BeginPlay()
{
	Super::BeginPlay();
	owner = GetOwner();
	if (!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName());
	}
	
}


// Called every frame
void URoom1_OpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (GetTotalMassOfActorsOnPlate()>TriggerMass) {
		OpenDoor();
	}
}


void URoom1_OpenDoor::OpenDoor()
{
	OnOpenRequest.Broadcast();
}

float URoom1_OpenDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.0f;
	TArray<AActor*> OverlappingActors;
	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	for (const auto& Actor : OverlappingActors) {
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%lf Kg on pressure plate"), TotalMass);
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());
	}
	return TotalMass;
}

