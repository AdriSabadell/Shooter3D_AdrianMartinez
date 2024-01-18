#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet1.generated.h"

DECLARE_MULTICAST_DELEGATE(FBulletCollisionDelegate);

UCLASS()
class SHOOTER3D_ADRIAN_API ABullet1 : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ABullet1();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Add a variable to control bullet speed
    UPROPERTY(EditAnywhere, Category = "Bullet")
    float BulletSpeed;

    // Declare the collision component
    UPROPERTY(VisibleAnywhere)
    class UBoxComponent* CollisionComponent;

    // Declare the bullet collision delegate
    FBulletCollisionDelegate OnBulletCollision;

    // Function to handle bullet movement
    void MoveBullet(float DeltaTime);

    // Function to handle bullet collision
    UFUNCTION()
    void OnBulletHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
