// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PlanetSixCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Net/UnrealNetwork.h"
#include "Engine.h"
#include "AttributesComponent.h"

//////////////////////////////////////////////////////////////////////////
// APlanetSixCharacter

APlanetSixCharacter::APlanetSixCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	//Initialize player's health
	MaxHealth = 100.f;
	CurrentHealth = MaxHealth;

	//Initialize Attributes


	//bReplicates = true;
	//bReplicateMovement = true;
}

//////////////////////////////////////////////////////////////////////////
// Input

void APlanetSixCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlanetSixCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlanetSixCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &APlanetSixCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &APlanetSixCharacter::LookUpAtRate);

	//adding specific inputs for the game:
	PlayerInputComponent->BindAction("Interaction", IE_Pressed, this, &APlanetSixCharacter::Interact);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &APlanetSixCharacter::Reload);
	PlayerInputComponent->BindAction("Melee Attack", IE_Pressed, this, &APlanetSixCharacter::MeleeAttack);
	PlayerInputComponent->BindAction("Skill 1", IE_Pressed, this, &APlanetSixCharacter::Skill1);
	PlayerInputComponent->BindAction("Skill 2", IE_Pressed, this, &APlanetSixCharacter::Skill2);
	PlayerInputComponent->BindAction("Skill 3", IE_Pressed, this, &APlanetSixCharacter::Skill3);
	PlayerInputComponent->BindAction("Inventory", IE_Pressed, this, &APlanetSixCharacter::Inventory);
	PlayerInputComponent->BindAction("Quest Log", IE_Pressed, this, &APlanetSixCharacter::QuestLog);
	PlayerInputComponent->BindAction("Skills Menu", IE_Pressed, this, &APlanetSixCharacter::SkillsMenu);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlanetSixCharacter::Sprint);
	PlayerInputComponent->BindAction("Ranged Weapon Zoom", IE_Pressed, this, &APlanetSixCharacter::Zoom);
	PlayerInputComponent->BindAction("Fire Ranged Weapon", IE_Pressed, this, &APlanetSixCharacter::Shoot);
	PlayerInputComponent->BindAction("Change To Weapon 1", IE_Pressed, this, &APlanetSixCharacter::ChangeWeapon1);
	PlayerInputComponent->BindAction("Change To Weapon 2", IE_Pressed, this, &APlanetSixCharacter::ChangeWeapon2);
	PlayerInputComponent->BindAction("Change To Weapon 3", IE_Pressed, this, &APlanetSixCharacter::ChangeWeapon3);
	PlayerInputComponent->BindAxis("Change Weapon ScrollWheel", this, &APlanetSixCharacter::ChangeWeaponScroll);

}

void APlanetSixCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void APlanetSixCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void APlanetSixCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APlanetSixCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

//////////////////////////////////////////////////////////////////////////
// Replicated Properties

void APlanetSixCharacter::GetLifetimeReplicatedProps(TArray <FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Replicates current health.
	DOREPLIFETIME(APlanetSixCharacter, CurrentHealth);
}

void APlanetSixCharacter::OnHealthUpdate()
{
	//client-specific functionality
	if (IsLocallyControlled())
	{
		FString healthMessage = FString::Printf(TEXT("You now have %f health remaining."), CurrentHealth);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, healthMessage);

		if (CurrentHealth <= 0)
		{
			FString deathMessage = FString::Printf(TEXT("You are dead. Waiting for revive..."));
		}
	}

	//server specific functionality
	if (GetLocalRole() == ROLE_Authority)
	{
		FString healthMessage = FString::Printf(TEXT("%s now has %f health remaining."), *GetFName().ToString(), CurrentHealth);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, healthMessage);
	}

	//functions that occur on all machines.
	/** Any special functionality that should occur as a result of damage or death should be placed here */

}

void APlanetSixCharacter::OnRep_CurrentHealth()
{
	OnHealthUpdate();
}

void APlanetSixCharacter::Interact()
{

	if (IsinperimiterofNPC == true) 
	{
		indexdialogue++;

		if (DialogueWidgetClass)
		{
			if (indexdialogue % 2 == 1)
			{
				widgetDialogue = CreateWidget<UNPCDialogueWidget>(GetWorld(), DialogueWidgetClass);
				widgetDialogue->AddToViewport();
				
			}

			if (indexdialogue % 2 == 0)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("remove text from viewport"));
				widgetDialogue->RemoveFromParent();

			}

	}

    }

	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("go near an NPC "));
	}
	
	
}

/** Reload the player's weapon */
void APlanetSixCharacter::Reload()
{

}

/** Melee Attack with any weapon */
void APlanetSixCharacter::MeleeAttack()
{

}

/** Send a Skill */
void APlanetSixCharacter::Skill(int32 SkillNumber)
{
	if (SkillNumber < 4 && SkillNumber > 0)
	{

	}
}

/** skill 1 */
void APlanetSixCharacter::Skill1()
{
	Skill(1);
}

/** skill 2 */
void APlanetSixCharacter::Skill2()
{
	Skill(2);
}

/** skill 3 */
void APlanetSixCharacter::Skill3()
{
	Skill(3);
}

/** Open the inventory */
void APlanetSixCharacter::Inventory()
{

}

/** Open the quest log */
void APlanetSixCharacter::QuestLog()
{

}

/** Open the skills menu */
void APlanetSixCharacter::SkillsMenu()
{

}

/** Sprint */
void APlanetSixCharacter::Sprint()
{

}

/** Zoom with a distance weapon */
void APlanetSixCharacter::Zoom()
{

}

/** Shoot */
void APlanetSixCharacter::Shoot()
{

}

/** Change Weapon depending on 1, 2, 3 or scrollwheel */
void APlanetSixCharacter::ChangeWeaponScroll(float WeaponNumber)
{
	if (WeaponNumber != 0.0f)
	{
		if ((int32)WeaponNumber > 0 && (int32)WeaponNumber < 4)
		{
			ChangeWeapon(1); //TODO change the logic of changing weapons
		}
		if ((int32)WeaponNumber < 0 && (int32)WeaponNumber > -4)
		{
			ChangeWeapon(3); //TODO change the logic of changing weapons
		}
	}
}

/** Change Weapon depending on 1, 2, 3 or scrollwheel */
void APlanetSixCharacter::ChangeWeapon(int32 WeaponNumber)
{

}

/** Change Weapon depending on 1, 2, 3 or scrollwheel */
void APlanetSixCharacter::ChangeWeapon1()
{
	ChangeWeapon(1);
}

/** Change Weapon depending on 1, 2, 3 or scrollwheel */
void APlanetSixCharacter::ChangeWeapon2()
{
	ChangeWeapon(2);
}

/** Change Weapon depending on 1, 2, 3 or scrollwheel */
void APlanetSixCharacter::ChangeWeapon3()
{
	ChangeWeapon(3);
}