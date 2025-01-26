// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle/BaseObstacle.h"
#include "Components/CapsuleComponent.h"
#include "PropObstacle.generated.h"

/**
 * 
 */
UCLASS()
class SHINEUP_2D_API APropObstacle : public ABaseObstacle
{
	GENERATED_BODY()

public:

	APropObstacle();

protected:

	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Base")
	USceneComponent* DefaultComponent;

	UPROPERTY(EditDefaultsOnly,Category = "Collider")
	UCapsuleComponent* BaseCollider;

	//Function That Triggers On Overlap Event
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
