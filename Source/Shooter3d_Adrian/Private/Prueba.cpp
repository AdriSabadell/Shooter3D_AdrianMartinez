#include "Prueba.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
APrueba::APrueba()
{
	PrimaryActorTick.bCanEverTick = true;
	OnActorBeginOverlap.AddDynamic(this, &APrueba::DestroyActorOnOverlap);
}

void APrueba::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APrueba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveForward();
}

void APrueba::MoveForward()
{
	FVector NewLocation = GetActorLocation() + (GetActorForwardVector() * ForwardSpeed * GetWorld()->GetDeltaSeconds());
	SetActorLocation(NewLocation);
}


void APrueba::DestroyActorOnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnBulletHit.IsBound())
	{
		OnBulletHit.Broadcast();
	}

	Destroy();
}
