// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/BubblePlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"



ABubblePlayerController::ABubblePlayerController()
{
	//Setting The Mouse Cursor To Always Show
	bShowMouseCursor = true;
}

void ABubblePlayerController::BeginPlay()
{

	Super::BeginPlay();

	//Setting Up The MappingContext To The Game
	if (UEnhancedInputLocalPlayerSubsystem* EnhancedSubsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
	{
		EnhancedSubsystem->ClearAllMappings();
		EnhancedSubsystem->AddMappingContext(BubbleMappingContext, 0);
	}

	//Binding Input And Its Function
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(this->InputComponent))
	{
		//EnhancedInput->BindAction(MouseLeftClickAction, ETriggerEvent::Started, this, &ABubblePlayerController::OnMouseLeftClickFunction);

		EnhancedInput->BindAction(TouchAction, ETriggerEvent::Started, this, &ABubblePlayerController::OnHandleTouch);
	}
}


const FVector ABubblePlayerController::PerformeLineTrace(FVector2D TouchLocation)
{
	//Storing The World Values For Mouse Cursor
	FVector WorldLocation, WorldDirection;

	//Converting Mouse Location To World Space
	if (DeprojectScreenPositionToWorld(TouchLocation.X,TouchLocation.Y,WorldLocation, WorldDirection))
	{
	FVector TraceEnd = WorldLocation + (WorldDirection * LineTraceRange);

	//Setting Up Query Params
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(GetPawn());
	TraceParams.bTraceComplex = false;

	FHitResult HitResult;

	//Perfoming The Line Trace
	bool IsHit = GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation, TraceEnd, ECC_Visibility, TraceParams);

	   if (IsHit)
	   {
		  return HitResult.ImpactPoint;
	   }
	}

	return FVector::ZeroVector;

}

void ABubblePlayerController::OnHandleTouch(const FInputActionValue& InputValue)
{
	FVector2D Value = InputValue.Get<FVector2D>();
	
	FVector TraceLocation = PerformeLineTrace(Value);

	//Checking If LineTrace Result In Returing Actual FVector
	if (TraceLocation != FVector::ZeroVector)
	{
		if (TraceLocation != FVector::ZeroVector)
		{
			if (AActor* BubbleActor = UGameplayStatics::GetActorOfClass(GetWorld(), GetPawn()->GetClass()))
			{
				if (UPrimitiveComponent* BubbleRootComponent = Cast<UPrimitiveComponent>(BubbleActor->GetRootComponent()))
				{
					// Calculate impulse direction
					FVector Direction = (BubbleActor->GetActorLocation() - TraceLocation).GetSafeNormal();

					// Apply constant impulse strength
					FVector ImpulseToAct = Direction * ImpulseStrength;

					BubbleRootComponent->AddImpulse(ImpulseToAct, NAME_None, true);
				}
			}
		}
	}
}
