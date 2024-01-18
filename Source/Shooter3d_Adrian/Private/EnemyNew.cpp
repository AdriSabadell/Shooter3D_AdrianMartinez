
#include "EnemyNew.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"


AEnemyNew::AEnemyNew()
{
	PrimaryActorTick.bCanEverTick = true;
	OnActorBeginOverlap.AddDynamic(this, &AEnemyNew::DestroyActorOnOverlap);
	Vidas = 5;
	DetectionRange = 1000.0f;
	GetCharacterMovement()->MaxWalkSpeed = 250.0f;

	LastShootTime = 0.0f;
	ShootCooldown = 2.0f; 
}

void AEnemyNew::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
}

void AEnemyNew::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);


	if (PlayerCharacter)
	{
		FVector PlayerLocation = PlayerCharacter->GetActorLocation();
		FVector PerseguidorLocation = GetActorLocation();

		float DistanceToPlayer = FVector::Distance(PlayerLocation, PerseguidorLocation);

		if (DistanceToPlayer <= DetectionRange)
		{

			FVector DirectionToPlayer = (PlayerLocation - PerseguidorLocation).GetSafeNormal();

			FRotator LookAtRotation = DirectionToPlayer.Rotation();

			FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), LookAtRotation, DeltaTime, 5.0f);

			SetActorRotation(NewRotation);

			FVector NewLocation = PerseguidorLocation + (DirectionToPlayer * GetCharacterMovement()->MaxWalkSpeed * DeltaTime);
			SetActorLocation(NewLocation);

			Shoot();

		}
	}

}


void AEnemyNew::DestroyActorOnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor->ActorHasTag("Bala1"))
	{
		RecibirGolpe();
	}
	if (OtherActor && OtherActor->ActorHasTag("Bala2"))
	{
		RecibirGolpe2();
	}

}


void AEnemyNew::RecibirGolpe()
{
	Vidas--;
	if (Vidas <= 0)
	{
		Destroy();
	}
}

void AEnemyNew::RecibirGolpe2()
{
	Vidas -= 2;
	if (Vidas <= 0)
	{
		Destroy();
	}
}


void AEnemyNew::Shoot()
{
	if ((GetWorld()->GetTimeSeconds() - LastShootTime) >= ShootCooldown)
	{
		if (BulletBlueprint1)
		{
			FVector SpawnLocation = GetActorLocation() + (GetActorForwardVector() * DistanceFromPlayer);
			FRotator SpawnRotation = GetActorRotation();
			AActor* Bullet = GetWorld()->SpawnActor<AActor>(BulletBlueprint1, SpawnLocation, SpawnRotation);
			LastShootTime = GetWorld()->GetTimeSeconds(); 
		}
	}
}
