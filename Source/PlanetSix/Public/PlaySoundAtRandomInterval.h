// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Sound/SoundCue.h"
#include "PlaySoundAtRandomInterval.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class PLANETSIX_API UPlaySoundAtRandomInterval : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UPlaySoundAtRandomInterval();

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
        TArray< USoundCue*> SoundCues UMETA(ExposeOnSpawn = "true");
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
        float MinTimeDelay UMETA(ExposeOnSpawn = "true");
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
        float MaxTimeDelay UMETA(ExposeOnSpawn = "true");




protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:

    UFUNCTION(BlueprintCallable)
        float ScaleToDelay(float value, float min, float max);

    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
