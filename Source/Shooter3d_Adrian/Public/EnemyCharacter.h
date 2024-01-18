#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class SHOOTER3D_ADRIAN_API AEnemyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AEnemyCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
    class UBoxComponent* DetectionRange;

    UPROPERTY(EditAnywhere, Category = "AI", meta = (AllowPrivateAccess = "true"))
    float FollowSpeed;

    AActor* TargetPlayer;

    bool bCanFollow;  // Nueva bandera para controlar el seguimiento

    UFUNCTION()
    void OnDetectionRangeOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnDetectionRangeOverlapEnd(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    // Establece el jugador objetivo al que el enemigo seguirá
    void SetTargetPlayer();

    // Implementa la lógica para seguir al jugador
    void FollowPlayer();
};