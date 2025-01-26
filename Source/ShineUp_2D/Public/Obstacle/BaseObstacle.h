// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseObstacle.generated.h"

UCLASS()
class SHINEUP_2D_API ABaseObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseObstacle();

protected:
	virtual void BeginPlay() override;

	//Common Function For Child Class That Class On Collison Trigger
	UFUNCTION()
	virtual void OnActorCollisionOverlap(AActor* CollidedActor);

};
