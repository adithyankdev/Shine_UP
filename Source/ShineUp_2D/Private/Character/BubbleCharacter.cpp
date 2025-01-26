

#include "Character/BubbleCharacter.h"
#include "Runtime/Engine/Public/TimerManager.h"

ABubbleCharacter::ABubbleCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	CharacterFlipBookComp = CreateDefaultSubobject<UPaperFlipbookComponent>("PlayerFlipBook");
	CharacterFlipBookComp->SetupAttachment(RootComponent);

}

void ABubbleCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABubbleCharacter::OnPlayerDestroy()
{
	CharacterFlipBookComp->SetFlipbook(BubblePopFlipbook);
	UnPossessed();
	if (UPrimitiveComponent* Root = Cast<UPrimitiveComponent>(GetRootComponent()))
	{
		Root->SetSimulatePhysics(false);
		
	}

	FTimerHandle PostAnimationTimer;
	GetWorld()->GetTimerManager().SetTimer(PostAnimationTimer, this, &ABubbleCharacter::OnPostPopAnimation,TimerValue);
}

//Used To Hide Mesh After The Animation
void ABubbleCharacter::OnPostPopAnimation()
{
	CharacterFlipBookComp->SetVisibility(false);

	MyBlueprintFunction();
}

void ABubbleCharacter::MyBlueprintFunction_Implementation()
{

}



