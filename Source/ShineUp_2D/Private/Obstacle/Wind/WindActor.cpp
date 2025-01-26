// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle/Wind/WindActor.h"

// Sets default values
AWindActor::AWindActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseScene = CreateDefaultSubobject<USceneComponent>("Scene");
	RootComponent = BaseScene;

	DirectionComponent = CreateDefaultSubobject<UArrowComponent>("Arrow");
	DirectionComponent->SetupAttachment(RootComponent);

	WindBlowCollision = CreateDefaultSubobject<UBoxComponent>("WindBlow");
	WindBlowCollision->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AWindActor::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void AWindActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	WindBlowCollision->OnComponentBeginOverlap.AddDynamic(this, &AWindActor::OnBeginOverlap);

}

void AWindActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (UPrimitiveComponent* RootComp = Cast<UPrimitiveComponent>(OtherActor->GetRootComponent()))
	{
		// Calculate impulse direction
		FVector Direction = (OtherActor->GetActorLocation() - DirectionComponent->GetComponentLocation()).GetSafeNormal();

		// Apply constant impulse strength
		FVector ImpulseToAct = Direction * WindImpulse;

		RootComp->AddImpulse(ImpulseToAct, NAME_None, true);
	}
}


