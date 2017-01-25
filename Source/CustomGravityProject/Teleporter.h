// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Teleporter.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CUSTOMGRAVITYPROJECT_API UTeleporter : public UActorComponent
{
	GENERATED_BODY()

private:

	void SetupInputComponent();
	void Teleport();
	UInputComponent* InputComponent = nullptr;

	

public:	
	// Sets default values for this component's properties
	UTeleporter();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
