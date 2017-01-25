// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGravityProject.h"
#include "SpherePosition.h"


// Sets default values for this component's properties
USpherePosition::USpherePosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpherePosition::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpherePosition::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	position = GetOwner()->GetActorLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%f - %f - %f"), position.X, position.Y, position.Z);

}

FVector USpherePosition::getPosition()
{
	return position;
}

