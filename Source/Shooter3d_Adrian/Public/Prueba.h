#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Prueba.generated.h"

DECLARE_MULTICAST_DELEGATE(FBulletHitDelegate);

UCLASS()
class SHOOTER3D_ADRIAN_API APrueba : public AActor
{
    GENERATED_BODY()

public:
    APrueba();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float ForwardSpeed = 100.0f;

    void MoveForward();

    UFUNCTION()
    void DestroyActorOnOverlap(AActor* OverlappedActor, AActor* OtherActor);

    FBulletHitDelegate OnBulletHit;
};
