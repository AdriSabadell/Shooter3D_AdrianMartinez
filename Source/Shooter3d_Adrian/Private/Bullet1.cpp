#include "Bullet1.h"
#include "Components/BoxComponent.h"

// Sets default values
ABullet1::ABullet1()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Set the default bullet speed
    BulletSpeed = 1000.0f;

    // Create and configure the collision component
    CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
    CollisionComponent->SetCollisionProfileName(TEXT("BlockAll"));
    CollisionComponent->OnComponentHit.AddDynamic(this, &ABullet1::OnBulletHit);
    RootComponent = CollisionComponent;
}

// Called when the game starts or when spawned
void ABullet1::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABullet1::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Move the bullet
    MoveBullet(DeltaTime);
}

// Function to handle bullet movement
void ABullet1::MoveBullet(float DeltaTime)
{
    // Move the bullet forward based on its speed
    FVector NewLocation = GetActorLocation() + GetActorForwardVector() * BulletSpeed * DeltaTime;
    SetActorLocation(NewLocation);
}

// Function to handle bullet collision
void ABullet1::OnBulletHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // Llamar al delegado para notificar sobre la colisión
    OnBulletCollision.Broadcast();

    Destroy();
}
