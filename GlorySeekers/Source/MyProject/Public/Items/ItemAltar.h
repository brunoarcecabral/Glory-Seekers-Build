// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyInterface.h"
#include "GameFramework/Actor.h"
#include "ItemAltar.generated.h"

class USphereComponent;
//FUNCION QUE DETECTA ACTIVACION
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAltarActivado);

UCLASS()
class MYPROJECT_API AItemAltar : public AActor, public IMyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemAltar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	virtual void Interact_Implementation(AActor* Actor) override;
	
	UPROPERTY()
	FOnAltarActivado OnAltarActivado;
	//TIMMER
	UPROPERTY()
	FTimerHandle AltarTimerHandle;
	
	void FinalizarActivacion();
	void ComenzarActivacion();
	
	UPROPERTY()
	AActor* InteractingActor;
	
	bool bJugadorEnArea = false;
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	
private:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> SphereCollision;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;
	
	UPROPERTY(VisibleAnywhere)
	bool bYaActivado = false;
	
	UFUNCTION()
	void ActivarAltar();

};
