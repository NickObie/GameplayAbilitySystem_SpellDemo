


#include "UI/WidgetController/SpellWidgetController.h"

void USpellWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void USpellWidgetController::BroadcastInitialValues()
{
	
}
