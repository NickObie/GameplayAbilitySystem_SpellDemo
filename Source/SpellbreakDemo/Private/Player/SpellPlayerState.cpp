


#include "Player/SpellPlayerState.h"

#include "AbilitySystem/SpellAbilitySystemComponent.h"
#include "AbilitySystem/SpellAttributeSet.h"

ASpellPlayerState::ASpellPlayerState()
{
	NetUpdateFrequency = 100.f;
	
	AbilitySystemComponent = CreateDefaultSubobject<USpellAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<USpellAttributeSet>("AttributeSet");
	
}

UAbilitySystemComponent* ASpellPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
