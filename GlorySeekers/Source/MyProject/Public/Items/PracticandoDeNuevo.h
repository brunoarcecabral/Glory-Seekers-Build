// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PracticandoDeNuevo.generated.h"

class UAudioComponent;

UCLASS()
class MYPROJECT_API APracticandoDeNuevo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APracticandoDeNuevo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UStaticMeshComponent> MeshDeCPP;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UStaticMeshComponent> MeshDeCPP2;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UAudioComponent> AudioBox;

};
