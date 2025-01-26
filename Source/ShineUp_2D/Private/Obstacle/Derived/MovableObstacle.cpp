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

	DirectionalArrow = CreateDefaultSubobject<UArrowComponent>("Arrow");
	DirectionalArrow->SetupAttachment(RootComponent);

	ChangeInTime = ConstantInterval;
}

void AMovableObstacle::BeginPlay()
{
	Super::BeginPlay();

	//Binding The Delegate And Function
	BaseCollider->OnComponentBeginOverlap.AddDynamic(this, &AMovableObstacle::OnBeginOverlap);

	//Triggering The TrunTimer Function For Counting Down
	StartTurnTimer();

}

void AMovableObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Moving The Actor Frame By Frame
	AddActorLocalOffset(((DirectionalArrow->GetRightVector())*Speed) * DeltaTime);

}

void AMovableObstacle::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnActorCollisionOverlap(OtherActor);
}

void AMovableObstacle::StartTurnTimer()
{
	//Repeatadly Calling On Every Second For Decrementing The Count
	GetWorld()->GetTimerManager().SetTimer(TurnTimerHandle, this, &AMovableObstacle::UpdateTunrTimer, 1, true);
}

void AMovableObstacle::UpdateTunrTimer()
{
	ChangeInTime--;
	if (ChangeInTime == 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(TurnTimerHandle);

        //Turing The Actor
		FRotator CurrentRotation = GetActorRotation();
		CurrentRotation.Yaw += 180.0f; // Add 180 degrees to the current Z-axis rotation (Yaw)
		SetActorRotation(CurrentRotation);

		OnTurnTimerRunsOut();
	}
}

//Function To Re-start The Timer When It Turn Out To Zero
void AMovableObstacle::OnTurnTimerRunsOut()
{
	//Reset Timer
	ChangeInTime = ConstantInterval;
	
	StartTurnTimer();
}

