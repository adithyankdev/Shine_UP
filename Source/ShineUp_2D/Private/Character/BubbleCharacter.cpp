

#include "Character/BubbleCharacter.h"

ABubbleCharacter::ABubbleCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ABubbleCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABubbleCharacter::OnPlayerDestroy()
{
	UnPossessed();
	Destroy();
}

void ABubbleCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



