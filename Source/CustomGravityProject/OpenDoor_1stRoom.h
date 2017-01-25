// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor_1stRoom.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCloseRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CUSTOMGRAVITYPROJECT_API UOpenDoor_1stRoom : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor_1stRoom();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void OpenDoor();

	void CloseDoor();

	UPROPERTY(BlueprintAssignable)
		FOnOpenRequest OnOpenRequest;

	UPROPERTY(BlueprintAssignable)
		FOnCloseRequest OnCloseRequest;


private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float TriggerMass = 10.0f;

	AActor *owner = nullptr;

	float GetTotalMassOfActorsOnPlate();
	
};
