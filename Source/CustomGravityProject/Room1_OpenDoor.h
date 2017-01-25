// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Room1_OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFROnOpenRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CUSTOMGRAVITYPROJECT_API URoom1_OpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URoom1_OpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void OpenDoor();

	UPROPERTY(BlueprintAssignable)
		FFROnOpenRequest OnOpenRequest;


private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float TriggerMass = 90.0f;

	AActor *owner = nullptr;

	float GetTotalMassOfActorsOnPlate();
	
};
