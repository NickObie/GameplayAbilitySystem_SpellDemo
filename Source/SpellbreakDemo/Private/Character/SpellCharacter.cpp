


#include "Character/SpellCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/SpellPlayerController.h"
#include "Player/SpellPlayerState.h"
#include "UI/HUD/SpellHUD.h"

ASpellCharacter::ASpellCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement() ->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
}

void ASpellCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();
}

void ASpellCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	InitAbilityActorInfo();
}

void ASpellCharacter::InitAbilityActorInfo()
{
	ASpellPlayerState* SpellPlayerState = GetPlayerState<ASpellPlayerState>();
	check(SpellPlayerState);
	SpellPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SpellPlayerState, this);
	
	AbilitySystemComponent = SpellPlayerState->GetAbilitySystemComponent();
	AttributeSet = SpellPlayerState->GetAttributeSet();

	if (ASpellPlayerController* SpellPlayerController = Cast<ASpellPlayerController>(GetController()))
	{
		if(ASpellHUD* SpellHUD = Cast<ASpellHUD>(SpellPlayerController->GetHUD()))
		{
			SpellHUD->InitOverlay(SpellPlayerController, SpellPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	
}


