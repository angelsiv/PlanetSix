// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ClassComponent.generated.h"

UENUM(BlueprintType)
enum class EFaction : uint8
{
	Pirates UMETA(DisplayName = "Pirates"),
	Vanguard UMETA(DisplayName = "Vanguard"),
	Unionists UMETA(DisplayName = "Unionists"),
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PLANETSIX_API UClassComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UClassComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		FName ClassName;
	UPROPERTY(VisibleAnywhere)
		FString ClassDescription;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
