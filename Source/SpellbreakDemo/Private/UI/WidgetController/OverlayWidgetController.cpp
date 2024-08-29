


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/SpellAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const USpellAttributeSet* SpellAttributeSet = CastChecked<USpellAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(SpellAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(SpellAttributeSet->GetMaxHealth());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const USpellAttributeSet* SpellAttributeSet = CastChecked<USpellAttributeSet>(AttributeSet);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SpellAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SpellAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
