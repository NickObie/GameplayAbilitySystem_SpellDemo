


#include "Character/SpellEnemy.h"

#include "AbilitySystem/SpellAbilitySystemComponent.h"
#include "AbilitySystem/SpellAttributeSet.h"

ASpellEnemy::ASpellEnemy()
{
	AbilitySystemComponent = CreateDefaultSubobject<USpellAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<USpellAttributeSet>("AttributeSet");
}

void ASpellEnemy::HighlightActor()
{
	bHighlighted = true;
}

void ASpellEnemy::UnHighlightActor()
{
	bHighlighted = false;
}

void ASpellEnemy::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
