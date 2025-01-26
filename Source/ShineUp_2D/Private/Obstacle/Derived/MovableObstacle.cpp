// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle/Derived/MovableObstacle.h"
#include "Runtime/Engine/Public/TimerManager.h"

AMovableObstacle::AMovableObstacle()
{
	PrimaryActorTick.bCanEverTick = true;;

	DefaultComponent = CreateDefaultSubobject<USceneComponent>("Scene Component");
	RootComponent = DefaultComponent;

	BaseCollider = CreateDefaultSubobject<UCapsuleComponent>("Capsule Collision");
	BaseCollider->SetupAttachment(RootComponent);


}

void AMovableObstacle::BeginPlay()
{
	Super::BeginPlay();

	//Binding The Delegate And Function
	BaseCollider->OnComponentBeginOverlap.AddDynamic(this, &AMovableObstacle::OnBeginOverlap);

}

void AMovableObstacle::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnActorCollisionOverlap(OtherActor);
}

