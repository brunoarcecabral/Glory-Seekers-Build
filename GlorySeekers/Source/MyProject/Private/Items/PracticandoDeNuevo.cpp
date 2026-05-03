// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/PracticandoDeNuevo.h"

#include "Components/AudioComponent.h"


// Sets default values
APracticandoDeNuevo::APracticandoDeNuevo()

{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshDeCPP = CreateDefaultSubobject<UStaticMeshComponent>("MeshDeCPP");
	RootComponent = MeshDeCPP;
	
	MeshDeCPP2 = CreateDefaultSubobject<UStaticMeshComponent>("MeshDeCPP2");
	MeshDeCPP2->SetupAttachment(RootComponent);
	
	AudioBox = CreateDefaultSubobject<UAudioComponent>("AudioBox");
	AudioBox->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APracticandoDeNuevo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APracticandoDeNuevo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

