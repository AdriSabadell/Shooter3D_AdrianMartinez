// PruebaMuerte.cpp

#include "PruebaMuerte.h"
#include "Components/SphereComponent.h"

APruebaMuerte::APruebaMuerte()
{
    PrimaryActorTick.bCanEverTick = true;

    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
    CollisionSphere->InitSphereRadius(RangoDeSeguimiento);
    CollisionSphere->SetCollisionProfileName(TEXT("Trigger"));
    CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &APruebaMuerte::OnActorEnter);
    CollisionSphere->OnComponentEndOverlap.AddDynamic(this, &APruebaMuerte::OnActorExit);
    RootComponent = CollisionSphere;

    PosicionInicial = GetActorLocation();
}

void APruebaMuerte::BeginPlay()
{
    Super::BeginPlay();
}

void APruebaMuerte::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (ActorAseguir)
    {
        FVector Direction = ActorAseguir->GetActorLocation() - GetActorLocation();
        float Distance = Direction.Size();

        Direction.Normalize();

        if (Distance <= RangoDeSeguimiento)
        {
            FVector NewLocation = GetActorLocation() + Direction * VelocidadDeSeguimiento * DeltaTime;
            SetActorLocation(NewLocation);
        }
    }
}

void APruebaMuerte::OnActorEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != this)
    {
        ActorAseguir = OtherActor;
    }
}

void APruebaMuerte::OnActorExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor && OtherActor == ActorAseguir)
    {
        ActorAseguir = nullptr;
    }
}