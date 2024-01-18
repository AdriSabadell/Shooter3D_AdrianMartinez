// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyNew.generated.h"

UCLASS()
class SHOOTER3D_ADRIAN_API AEnemyNew : public ACharacter
{
	GENERATED_BODY()


protected:

	virtual void BeginPlay() override;

	void Shoot();

	UPROPERTY(EditDefaultsOnly, Category = "Shooting")
	TSubclassOf<class AActor> BulletBlueprint1;

	UPROPERTY(EditDefaultsOnly, Category = "Shooting")
	float DistanceFromPlayer = 100.0f;



public:
	AEnemyNew();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void DestroyActorOnOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	int32 Vidas;


	void RecibirGolpe();
	void RecibirGolpe2();

private:
	UPROPERTY(EditAnywhere)
	float DetectionRange;

	ACharacter* PlayerCharacter;

	float LastShootTime;
	float ShootCooldown;
};
