


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/SpellAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
		const USpellAttributeSet* SpellAttributeSet = CastChecked<USpellAttributeSet>(AttributeSet);
	
		OnHealthChanged.Broadcast(SpellAttributeSet->GetHealth());
		OnMaxHealthChanged.Broadcast(SpellAttributeSet->GetMaxHealth());
}
