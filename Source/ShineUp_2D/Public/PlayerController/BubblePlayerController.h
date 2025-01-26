// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "BubblePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHINEUP_2D_API ABubblePlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ABubblePlayerController();

protected:

	void BeginPlay()override;

	//Base Mapping Context 
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* BubbleMappingContext;

	//Touch Input Action For Controlling Bubble Character
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* TouchAction;

	//Function To Handle Touch Input
	void OnHandleTouch(const FInputActionValue& InputValue);

	//Function To Perfome Line Trace From The Mouse Cursor
	const FVector PerformeLineTrace(FVector2D TouchLocation);

	//Range Of The Line Trace To Be Casted
	const float LineTraceRange = 10000.0f;

	//Strength Of Impulse On Click 
	const float ImpulseStrength = 400.0f;

};
