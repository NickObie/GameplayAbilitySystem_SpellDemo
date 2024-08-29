

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SpellHUD.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UOverlayWidgetController;
struct FWidgetControllerParams;
class USpellUserWidget;
/**
 * 
 */
UCLASS()
class SPELLBREAKDEMO_API ASpellHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<USpellUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:
	
private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<USpellUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
