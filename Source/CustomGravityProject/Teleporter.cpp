// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGravityProject.h"
#include "Teleporter.h"

#define OUT //Les Output

// Sets default values for this component's properties
UTeleporter::UTeleporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	// bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UTeleporter::BeginPlay()
{
	Super::BeginPlay();

	SetupInputComponent();
	
}

void UTeleporter::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Input component found"));
		//Bind the input axis
		InputComponent->BindAction("Teleport", IE_Pressed, this, &UTeleporter::Teleport);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("%s missing physics input component"), *GetOwner()->GetName());
	}
}

void UTeleporter::Teleport() {
	UE_LOG(LogTemp, Error, TEXT("%s HELLO"), *GetOwner()->GetName());
	APawn* myPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	//FVector posJoueur = FVector(myPawn->GetActorLocation().X + 1000,myPawn->GetActorLocation().Y, myPawn->GetActorLocation().Z);
	//myPawn->SetActorLocation(posJoueur);

}


// Called every frame
void UTeleporter::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
}

