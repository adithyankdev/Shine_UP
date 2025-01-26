// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle/Derived/PropObstacle.h"

APropObstacle::APropObstacle()
{
	DefaultComponent = CreateDefaultSubobject<USceneComponent>("Scene Component");
	RootComponent = DefaultComponent;

	BaseCollider = CreateDefaultSubobject<UCapsuleComponent>("Capsule Collision");
	BaseCollider->SetupAttachment(RootComponent);
	
}

void APropObstacle::BeginPlay()
{
	Super::BeginPlay();

	BaseCollider->OnComponentBeginOverlap.AddDynamic(this, &APropObstacle::OnBeginOverlap);
}

void APropObstacle::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnActorCollisionOverlap(OtherActor);
}
