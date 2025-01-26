// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/BubbleCharInterface.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "BubbleCharacter.generated.h"

UCLASS()
class SHINEUP_2D_API ABubbleCharacter : public ACharacter , public IBubbleCharInterface
{
	GENERATED_BODY()

public:
	ABubbleCharacter();

protected:

	UPROPERTY(EditDefaultsOnly,Category = "Paper2D")
	UPaperFlipbookComponent* CharacterFlipBookComp;

	UPROPERTY(EditDefaultsOnly, Category = "Paper2D")
	UPaperFlipbook* BubblePopFlipbook;
			   
	virtual void BeginPlay() override;

	void OnPlayerDestroy() override;

	float const TimerValue = 0.7f;

	//Function Call When The Animation Finishes
	void OnPostPopAnimation();

};
