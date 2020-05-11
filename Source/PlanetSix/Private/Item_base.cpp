// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemInv.h"
#include "Item_base.h"


// Sets default values
AItem_base::AItem_base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	sphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(sphereCollider);
	sphereCollider->InitSphereRadius(70.0f);
	sphereCollider->SetCollisionProfileName(TEXT("Item"));


}

// Called when the game starts or when spawned
void AItem_base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem_base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UitemInv* AItem_base::ToItemInv()
{
	//UitemInv::UitemInv(id, displayName, weight, value, quantity);		// item = UitemInv(id, displayName, weight, value, quantity);
	//UitemInv item = UitemInv::getNewItemInv(id, displayName, weight, value, quantity);

	//return UitemInv::UitemInv(id, displayName, weight, value, quantity);



	//auto item = NewObject<UitemInv>(TEXT("plswork"));
	auto item = NewObject<UitemInv>(GetTransientPackage(), MakeUniqueObjectName(GetTransientPackage(), UitemInv::StaticClass(), TEXT("Item")));
		

	//auto item = UitemInv::UitemInv(id, displayName, weight, value, quantity) ;
	//item.getId();
	//item.self = &item;
	return item;
}

