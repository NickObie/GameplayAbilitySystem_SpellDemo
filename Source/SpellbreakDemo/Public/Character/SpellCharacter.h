

#pragma once

#include "CoreMinimal.h"
#include "Character/SpellCharacterBase.h"
#include "SpellCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SPELLBREAKDEMO_API ASpellCharacter : public ASpellCharacterBase
{
	GENERATED_BODY()
public:
	ASpellCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};
