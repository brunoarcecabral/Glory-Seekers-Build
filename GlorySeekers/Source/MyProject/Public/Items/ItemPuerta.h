// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemPuerta.generated.h"

class AItemAltar;

UCLASS()
class MYPROJECT_API AItemPuerta : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemPuerta();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:	
	
	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<class UBoxComponent> BoxCollision;
	
	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<class UStaticMeshComponent> Mesh;
	
	UPROPERTY(EditAnywhere, Category = "Settings")
	float DetectionRadius = 300.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	TArray<TObjectPtr<AItemAltar>>Items;
	
	UFUNCTION()
	void OnAltarActivation();
	
	UPROPERTY()
	int CantidaddeAltares = 0;
	
	UPROPERTY()
	int CantidaddeAltaresActivados = 0;
	
	
};
