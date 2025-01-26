// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BubbleCharInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBubbleCharInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHINEUP_2D_API IBubbleCharInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void OnPlayerDestroy() = 0;

};
