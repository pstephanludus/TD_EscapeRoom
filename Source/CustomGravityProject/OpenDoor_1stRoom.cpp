// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGravityProject.h"
#include "OpenDoor_1stRoom.h"


// Sets default values for this component's properties
UOpenDoor_1stRoom::UOpenDoor_1stRoom()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor_1stRoom::BeginPlay()
{
	Super::BeginPlay();
	owner = GetOwner();
	if (!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName());
	}
}


// Called every frame
void UOpenDoor_1stRoom::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	if (GetTotalMassOfActorsOnPlate()>TriggerMass) {
		CloseDoor();
	}
	else {
		OpenDoor();
	}
}

void UOpenDoor_1stRoom::OpenDoor()
{
	OnOpenRequest.Broadcast();
}

void UOpenDoor_1stRoom::CloseDoor()
{
	OnCloseRequest.Broadcast();
}

float UOpenDoor_1stRoom::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.0f;
	TArray<AActor*> OverlappingActors;
	UE_LOG(LogTemp, Warning, TEXT("%lf Kg on pressure plate"), TotalMass);
	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	for (const auto& Actor : OverlappingActors) {
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%lf Kg on pressure plate"), TotalMass);
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());
	}
	return TotalMass;
}



