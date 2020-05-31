// This work is the sole property of 2Pow6 Games.


#include "WeaponComponent.h"
#include "Engine.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
	: PrimaryAmmo(20.f)
	, SecondaryAmmo(10.f)
	, TertiaryAmmo(5.f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("WeaponComp Initiated"));

}


// Called every frame
void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

