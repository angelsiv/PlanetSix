// This work is the sole property of 2Pow6 Games.


#include "PlaySoundAtRandomInterval.h"

// Sets default values for this component's properties
UPlaySoundAtRandomInterval::UPlaySoundAtRandomInterval()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlaySoundAtRandomInterval::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


float UPlaySoundAtRandomInterval::ScaleToDelay(float value, float min, float max)
{
	float size = max - min;
	float scaled = size * value;
	return value+min;
}

// Called every frame
void UPlaySoundAtRandomInterval::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

