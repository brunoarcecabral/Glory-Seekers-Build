// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemAltar.h"

#include "StateTreeTypes.h"
#include "Components/SphereComponent.h"
#include "DataWrappers/ChaosVDParticleDataWrapper.h"

// Sets default values
AItemAltar::AItemAltar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	RootComponent = SphereCollision;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AItemAltar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemAltar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AItemAltar::ActivarAltar()
{
	OnAltarActivado.Broadcast();
	bYaActivado = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Altar activado con Exito"));
}
void AItemAltar::Interact_Implementation(AActor* Actor)
{
	GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Red, "ItemAltar Interactuando, esperar 3 segundos");
	
	//Condiciones del timmer
	
	if (GetWorldTimerManager().IsTimerPaused(AltarTimerHandle)||bYaActivado) return;
	
	//Si El timer estaba pausado, lo reactivamos
	if (GetWorldTimerManager().IsTimerPaused(AltarTimerHandle))
	{
		GetWorldTimerManager().UnPauseTimer(AltarTimerHandle);
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, TEXT("Reanundo Activacion..."));
	}
	else
	{
		ComenzarActivacion();
	}
	
}



void AItemAltar::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	bJugadorEnArea = true;
}

void AItemAltar::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	if (GetWorldTimerManager().IsTimerActive(AltarTimerHandle))
	{
		GetWorldTimerManager().PauseTimer(AltarTimerHandle);
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Orange, TEXT("Activación Pausada, vuelve al altar"));
		{
			
		}
	}
}
void AItemAltar::FinalizarActivacion()
{
		GetWorldTimerManager().ClearTimer(AltarTimerHandle); //Limpiamos
		bYaActivado = true;
		
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Altar Activado con exitaso mal epico"));
}


void AItemAltar::ComenzarActivacion()
{
		GetWorldTimerManager().SetTimer(AltarTimerHandle, this, &AItemAltar::ActivarAltar, 5.0f, false);
}

