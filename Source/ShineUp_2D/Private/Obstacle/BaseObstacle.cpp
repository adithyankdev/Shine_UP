
#include "Obstacle/BaseObstacle.h"
#include "Interfaces/BubbleCharInterface.h"

ABaseObstacle::ABaseObstacle()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ABaseObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseObstacle::OnActorCollisionOverlap(AActor* CollidedActor)
{
	if (IBubbleCharInterface* Interface = Cast<IBubbleCharInterface>(CollidedActor))
	{
		Interface->OnPlayerDestroy();
	}
}



