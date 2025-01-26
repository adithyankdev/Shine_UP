// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle/BaseObstacle.h"
#include "Components/BoxComponent.h"
#include "BoxCollider.generated.h"

/**
 * 
 */
UCLASS()
class SHINEUP_2D_API ABoxCollider : public ABaseObstacle
{
	GENERATED_BODY()

public:

	ABoxCollider();

protected:

	void BeginPlay() override;

	//RootComponent
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BaseCollision;

	//Function That Triggers On Overlap Event
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
