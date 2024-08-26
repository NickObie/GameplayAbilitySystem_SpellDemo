

#pragma once

#include "CoreMinimal.h"
#include "Character/SpellCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "SpellEnemy.generated.h"

/**
 * 
 */
UCLASS()
class SPELLBREAKDEMO_API ASpellEnemy : public ASpellCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	ASpellEnemy();
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

protected:
	virtual void BeginPlay() override;
};
