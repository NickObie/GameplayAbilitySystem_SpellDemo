


#include "Character/SpellCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/SpellPlayerState.h"

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
}


