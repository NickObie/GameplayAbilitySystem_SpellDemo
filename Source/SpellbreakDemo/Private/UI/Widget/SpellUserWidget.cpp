


#include "UI/Widget/SpellUserWidget.h"

#include "UnrealWidgetFwd.h"

void USpellUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
