// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCDialogueWidget.h"
#include "QuestWidget.h"
#include "QuestActor.h"
#include "NPCQuestWidget.h"
#include "AttributesComponent.h"
#include "ClassComponent.h"
#include "Components/WidgetComponent.h"
#include "InventoryComponent.h"
#include "Net/UnrealNetwork.h"
#include "PlanetSixCharacter.generated.h"


USTRUCT(BlueprintType)
struct PLANETSIX_API FPlayerInfo
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
	FString UserName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
	bool HasQuestItem;

};



class APlayerController;
class ASkill;
class AMapTravel;

UCLASS(config = Game)
class APlanetSixCharacter : public ACharacter
{
	GENERATED_BODY()

		/** Camera boom positioning the camera behind the character */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

public:
	APlanetSixCharacter();

	//Player Stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, replicated)
		FString UserName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, replicated)
		int32 Level;
	//PlayerCharacter values
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FPlayerInfo Playerinfo;

	/** Property replication */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;


	/** Interact with object or player */
	void Interact();


	//boolean variable to check if player is in the perimeter of the player
	bool bIsInPerimiterOfNPC = false;


	      /*Dialogue Sections */
		//this the incrementor for widgetclass 
		int IndexDialogue = 0;
		int Incrementor = 0;

		//Specified Portal  
		AMapTravel* Portal;


		/*//this is to create the widget of the dialogue  
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DialogueWidgetUI")
			TSubclassOf<UUserWidget> DialogueWidgetClass;

		//this is for the specific dialogue 
		UNPCDialogueWidget* WidgetDialogue;*/


		//this is to create the widget of the NPCQuest  
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCQuestUI")
			TSubclassOf<UUserWidget>NPCQuestWidgetClass;

		//this is for the specific dialogue 
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCQuestUI")
		UNPCQuestWidget* WidgetQuestNPC;

		/*Quest Widget UI*/
		//this is to create teh quest LOG 
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QuestUIWidget")
			TSubclassOf<UUserWidget> QuestWidgetLog;

		//this is for the WidgetQuestLog
		UQuestWidget* WidgetQuestLog;

	//QuestInfos for player 
		TArray<FQuestInfo> QuestInfos;

	//Quest Accepted By Player
		FQuestInfo QuestAccepted;


	/** Player's inventory. */
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
		UInventoryComponent* InventoryComponent;

	/** Player's attributes. */
	UPROPERTY(BlueprintReadWrite, Category = "Attributes")
		UAttributesComponent* Attributes;

	/** Player's class. */
	UPROPERTY(BlueprintReadWrite, Category = "Attributes")
		UClassComponent* Class;

	/** Player's HUD. */
	UPROPERTY(EditDefaultsOnly, Category = "UI")
		UUserWidget* MainHUD;

	UPROPERTY(EditDefaultsOnly, Category = "IGMenu")
		TSubclassOf<UUserWidget> InGameMenu;

protected:
	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Reload the player's weapon */
	void Reload();

	/** Crouch  */

	/** Melee Attack with any weapon */
	void MeleeAttack();

	/** Send a Skill */
	UFUNCTION(BlueprintCallable)
		void Skill(int32 SkillNumber);

	/** skill 1 */
	void Skill1();

	/** skill 2 */
	void Skill2();

	/** skill 3 */
	void Skill3();

	/** Open the inventory */
	void Inventory();

	/** Open the quest log */
	void QuestLog();

	/** Open the skills menu */
	void SkillsMenu();

	/** Sprint */
	void Sprint();

	/** Zoom with a distance weapon */
	void Zoom();

	/** Shoot */
	void Shoot();

	/** Change Weapon depending on 1, 2, 3 or scrollwheel */
	void ChangeWeaponScroll(float WeaponNumber);

	/** Change Weapon depending on 1, 2, 3 or scrollwheel */
	void ChangeWeapon(int32 WeaponNumber);

	/** Change Weapon depending on 1, 2, 3 or scrollwheel */
	void ChangeWeapon1();

	/** Change Weapon depending on 1, 2, 3 or scrollwheel */
	void ChangeWeapon2();

	/** Change Weapon depending on 1, 2, 3 or scrollwheel */
	void ChangeWeapon3();

	/** Open Ingame Menu*/
	void OpenIngameMenu();

	/** Drop item on the ground*/
	UFUNCTION(BlueprintCallable)
	bool DropItem(FItemData item);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	//the distance an item is drop from the player;
	float DropDistance = 200;


public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	/** Updates the UI with the proper numbers */
	void UpdateUI();
	UFUNCTION(BlueprintCallable)
		void ReceiveDamage(float Damage);
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;




};
