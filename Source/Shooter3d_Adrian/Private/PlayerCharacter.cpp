#include "PlayerCharacter.h"



APlayerCharacter::APlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    OnActorBeginOverlap.AddDynamic(this, &APlayerCharacter::DestroyActorOnOverlap);
}

void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
    CurrentBulletType = 0;  
}

void APlayerCharacter::MoveForward(float AxisVal)
{
    AddMovementInput(GetActorForwardVector() * AxisVal);
}

void APlayerCharacter::MoveRight(float AxisVal)
{
    AddMovementInput(GetActorRightVector() * AxisVal);
}

void APlayerCharacter::SwitchBulletType()
{
    // Cambia entre los tipos de balas (0 y 1)
    CurrentBulletType = (CurrentBulletType == 0) ? 1 : 0;
}

void APlayerCharacter::Shoot()
{
    FVector SpawnLocation = GetActorLocation() + (GetActorForwardVector() * DistanceFromPlayer);
    FRotator SpawnRotation = GetActorRotation();

    TSubclassOf<class AActor> BulletType;

    if (CurrentBulletType == 0 && BulletBlueprint1)
    {
        BulletType = BulletBlueprint1;
    } 
    else if (CurrentBulletType == 1 && BulletBlueprint2)
    {
        BulletType = BulletBlueprint2;
    }

    AActor* Bullet = GetWorld()->SpawnActor<AActor>(BulletType, SpawnLocation, SpawnRotation);
   
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerCharacter::AddControllerYawInput);
    //PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &APlayerCharacter::Jump);
    PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &APlayerCharacter::Shoot);
    PlayerInputComponent->BindAction(TEXT("ChangeBulletType"), IE_Pressed, this, &APlayerCharacter::SwitchBulletType);
}

void APlayerCharacter::DestroyActorOnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
    if (OtherActor && OtherActor->ActorHasTag("Bala1"))
    {
        UE_LOG(LogTemp, Warning, TEXT("Muerte"));
    }
    

}