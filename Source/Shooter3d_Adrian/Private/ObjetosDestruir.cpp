#include "ObjetosDestruir.h"
#include "Components/BoxComponent.h"

// Sets default values
AObjetosDestruir::AObjetosDestruir()
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	// Crear un componente de caja para la colisión
	UBoxComponent* BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	// Asignar la función de manejo de colisiones
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AObjetosDestruir::OnOverlapBegin);

	// Inicializar el número de vidas
	Vidas = 5;
}

// Called when the game starts or when spawned
void AObjetosDestruir::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AObjetosDestruir::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObjetosDestruir::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Verificar si el otro actor es válido
	if (OtherActor)
	{
		// Recibir un golpe
		RecibirGolpe();
	}
}

void AObjetosDestruir::RecibirGolpe()
{
	// Reducir las vidas
	Vidas--;

	// Verificar si las vidas han llegado a cero
	if (Vidas <= 0)
	{
		// Destruir este objeto
		Destroy();
	}
}
