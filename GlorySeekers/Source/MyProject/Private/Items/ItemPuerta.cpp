// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemPuerta.h"

#include "Components/BoxComponent.h"
#include "Items/ItemAltar.h"

// Sets default values
AItemPuerta::AItemPuerta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;
	
	BoxCollision->SetBoxExtent(FVector(DetectionRadius, DetectionRadius, DetectionRadius));
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AItemPuerta::BeginPlay()
{
	Super::BeginPlay();
	
	CantidaddeAltares = Items.Num();
	
	//LA PUERTA ESCUCHA LOS EVENTOS--------------------------------------------------------------------------------------------------------------------------------------------.
	
	for (AItemAltar*Altar : Items)
	{
		if (Altar)
		{
			Altar->OnAltarActivado.AddDynamic(this, &AItemPuerta::OnAltarActivation);
		}
	}
	
}

// Called every frame
void AItemPuerta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//LOGICA DE ACTIVACION FINAL------------------------------------------------------------------------------------------------------------------------------------------------------

void AItemPuerta::OnAltarActivation()
{
	CantidaddeAltaresActivados++;
	if (CantidaddeAltaresActivados >= CantidaddeAltares)
	{
		Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("La Puerta se ha Abierto"));
	}
}

