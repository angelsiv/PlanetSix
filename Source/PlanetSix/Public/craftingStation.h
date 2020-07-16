// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryComponent.h"
#include "craftingStation.generated.h"


class UBoxComponent;



USTRUCT()
struct PLANETSIX_API FCraftingRecipe : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

public:
    // Sets default values for this component's properties
    FCraftingRecipe()
    {};

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TMap<int, int> ingredients;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FItemBaseData product;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool craftable = false;

};



UCLASS()
class PLANETSIX_API AcraftingStation : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AcraftingStation();


    TArray<FCraftingRecipe> PossibleRecipies;

    UPROPERTY(EditAnywhere)
        UBoxComponent* boxcomponent;

    FItemBaseData* RecipePointer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        class UDataTable* RecipeTable;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable)
    TArray<FCraftingRecipe> GetRecipies();

    UFUNCTION(BlueprintCallable)
        FCraftingRecipe GetRecipe(int index);
    UFUNCTION(BlueprintCallable)
        void LoadRecipies(TArray<FItemBaseData> inventory);
    UFUNCTION(BlueprintCallable)
        void Craft(int index, UInventoryComponent* inventory);
    //UFUNCTION(BlueprintCallable)
        void Craft(FCraftingRecipe Recipe, UInventoryComponent* inventory);
    UFUNCTION(BlueprintCallable)
        void VeriyCraftability(TArray<FItemBaseData> inventory);
    TArray<FCraftingRecipe> GetRecipeFromDataTable();

};
