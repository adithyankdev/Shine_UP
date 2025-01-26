// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "WindActor.generated.h"

UCLASS()
class SHINEUP_2D_API AWindActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AWindActor();

protected:

	virtual void BeginPlay() override;

	void Tick(float DeltaTime)override;


	UPROPERTY(EditDefaultsOnly)
	USceneComponent* BaseScene;

	UPROPERTY(EditDefaultsOnly)
	UArrowComponent* DirectionComponent;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* WindBlowCollision;


	float const WindImpulse = 2;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
