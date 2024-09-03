

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpellEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class SPELLBREAKDEMO_API ASpellEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpellEffectActor();
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
private:
};
