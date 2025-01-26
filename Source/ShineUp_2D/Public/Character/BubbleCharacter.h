// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/BubbleCharInterface.h"
#include "BubbleCharacter.generated.h"

UCLASS()
class SHINEUP_2D_API ABubbleCharacter : public ACharacter,public IBubbleCharInterface
{
	GENERATED_BODY()

public:
	ABubbleCharacter();

protected:
	virtual void BeginPlay() override;

	void OnPlayerDestroy() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
