#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

DECLARE_DELEGATE(FShootDelegate);

UCLASS()
class SHOOTER3D_ADRIAN_API APlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    APlayerCharacter();

    //virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


    UFUNCTION()
    void DestroyActorOnOverlap(AActor* OverlappedActor, AActor* OtherActor);

protected:
    virtual void BeginPlay() override;

    void MoveForward(float AxisVal);
    void MoveRight(float AxisVal);
    void Shoot();

    void SwitchBulletType();

    UPROPERTY(EditDefaultsOnly, Category = "Shooting")
    TSubclassOf<class AActor> BulletBlueprint1;


    UPROPERTY(EditDefaultsOnly, Category = "Shooting2")
    TSubclassOf<class AActor> BulletBlueprint2;

    UPROPERTY(EditDefaultsOnly, Category = "Shooting")
    float DistanceFromPlayer = 100.0f; 

    UPROPERTY(EditDefaultsOnly, Category = "Shooting2")
    float DistanceFromPlayer2 = 100.0f; 

    int32 CurrentBulletType;
};