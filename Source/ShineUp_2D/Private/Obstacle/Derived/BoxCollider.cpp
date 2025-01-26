// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle/Derived/BoxCollider.h"

ABoxCollider::ABoxCollider()
{
	BaseCollision = CreateDefaultSubobject<UBoxComponent>("Collider");
	RootComponent = BaseCollision;
}

void ABoxCollider::BeginPlay()
{
	Super::BeginPlay();

	//Binding The Event And Function
	BaseCollision->OnComponentBeginOverlap.AddDynamic(this, &ABoxCollider::OnBeginOverlap);
}

void ABoxCollider::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnActorCollisionOverlap(OtherActor);
}
