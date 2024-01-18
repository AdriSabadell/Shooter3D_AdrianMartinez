#include "EnemyCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

AEnemyCharacter::AEnemyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    DetectionRange = CreateDefaultSubobject<UBoxComponent>(TEXT("DetectionRange"));
    DetectionRange->SetupAttachment(RootComponent);
    DetectionRange->OnComponentBeginOverlap.AddDynamic(this, &AEnemyCharacter::OnDetectionRangeOverlapBegin);
    DetectionRange->OnComponentEndOverlap.AddDynamic(this, &AEnemyCharacter::OnDetectionRangeOverlapEnd);

    FollowSpeed = 500.0f;
    TargetPlayer = nullptr;
    bCanFollow = false;  // Inicializa la bandera como falsa
}

void AEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();

    SetTargetPlayer();
    bCanFollow = true;  // Habilita el seguimiento al comenzar el juego
}

void AEnemyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bCanFollow)
    {
        FollowPlayer();
    }
}

void AEnemyCharacter::SetTargetPlayer()
{
    // Obtén una referencia al jugador BP_Player y establécelo como el jugador objetivo
    TargetPlayer = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}

void AEnemyCharacter::FollowPlayer()
{
    if (TargetPlayer)
    {
        FVector TargetLocation = TargetPlayer->GetActorLocation();
        FVector CurrentLocation = GetActorLocation();

        FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();
        FVector NewLocation = CurrentLocation + Direction * FollowSpeed * GetWorld()->GetDeltaSeconds();

        SetActorLocation(NewLocation);
    }
}

void AEnemyCharacter::OnDetectionRangeOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    bCanFollow = true;
}

void AEnemyCharacter::OnDetectionRangeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    bCanFollow = false;
}
