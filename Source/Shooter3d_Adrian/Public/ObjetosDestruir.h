// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjetosDestruir.generated.h"

UCLASS()
class SHOOTER3D_ADRIAN_API AObjetosDestruir : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AObjetosDestruir();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Funci�n de manejo de colisiones
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Vidas del objeto
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	int32 Vidas;

	// Funci�n para recibir un golpe
	void RecibirGolpe();
};