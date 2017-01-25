// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "SpherePosition.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CUSTOMGRAVITYPROJECT_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

private:

	//How far ahead of the player can we reach in cm
	float Reach = 300.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	//Ray-cast abd grab what's in reach
	void Grab();

	// Called when grab key is released
	void Release();

	//fct called Physics default blueprint
	void FindPhysicsHandleComponent();

	//fct called Input action default blueprint
	void SetupInputComponent();

	//Return hit for first physics body reach
	const FHitResult GetFirstPhysicsBodyInReach();

	//Returns current start of reach Line
	FVector GetReachLineStart();


	//Returns current end of reach Line
	FVector GetReachLineEnd();

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
