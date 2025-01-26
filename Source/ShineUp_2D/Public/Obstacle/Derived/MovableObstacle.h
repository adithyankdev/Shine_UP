// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle/BaseObstacle.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "MovableObstacle.generated.h"

/**
 * 
 */
UCLASS()
class SHINEUP_2D_API AMovableObstacle : public ABaseObstacle
{
	GENERATED_BODY()

public:

	AMovableObstacle();

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Base")
	USceneComponent* DefaultComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Collider")
	UCapsuleComponent* BaseCollider;

	void BeginPlay() override;

	
	//Function That Triggers On Overlap Event
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	

};
