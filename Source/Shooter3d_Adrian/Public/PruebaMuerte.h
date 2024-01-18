// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PruebaMuerte.generated.h"

UCLASS()
class SHOOTER3D_ADRIAN_API APruebaMuerte : public ACharacter
{
	GENERATED_BODY()

public:
    APruebaMuerte();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere)
    float RangoDeSeguimiento = 500.0f;

    UPROPERTY(EditAnywhere)
    float VelocidadDeSeguimiento = 5.0f;

    UPROPERTY(EditAnywhere)
    AActor* ActorAseguir;

    FVector PosicionInicial;

    UFUNCTION()
    void OnActorEnter(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnActorExit(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UPROPERTY(VisibleAnywhere)
    class USphereComponent* CollisionSphere;

};