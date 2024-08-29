


#include "Player/SpellPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interaction/EnemyInterface.h"

ASpellPlayerController::ASpellPlayerController()
{
	bReplicates = true;
}

void ASpellPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	check(SpellContext);

	if(	UEnhancedInputLocalPlayerSubsystem* Subsystem =	ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(SpellContext, 0);

	}
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;

	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

	GetCharacter()->GetCharacterMovement()->bApplyGravityWhileJumping = true;
	GetCharacter()->GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacter()->GetCharacterMovement()->AirControl = 0.75f;
	GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = 1000.f;
	GetCharacter()->GetCharacterMovement()->BrakingDecelerationWalking = 800.f;
	GetCharacter()->GetCharacterMovement()->MinAnalogWalkSpeed = 1000.f;
}

void ASpellPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASpellPlayerController::Move);
	
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ASpellPlayerController::ControllerJump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ASpellPlayerController::ControllerStopJump);
}

void ASpellPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void ASpellPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = CurrentActor;
	CurrentActor = CursorHit.GetActor();

	/**
	 * Line Trace from cursor. There are several scenarios:
	 *  A. LastActor is null && CurrentActor is null
	 *    - Do Nothing
	 *  B. LastActor is null && CurrentActor is valid
	 *    - Highlight CurrentActor
	 *  C. LastActor is valid && CurrentActor is Valid and LastActor is != CurrentActor
	 *	  - UnHighlight LastActor and Highlight CurrentActor
	 *	D. LastActor is Valid && CurrentActor is null
	 *	  - Unhighlight LastActor
	 *  E. Both Actors are valid, and are the same actor
	 *	  - Do Nothing
	 */

	if (CurrentActor != LastActor)
	{
		if (LastActor != nullptr)
		{
			LastActor->UnHighlightActor();
		}

		if (CurrentActor != nullptr)
		{
			CurrentActor->HighlightActor();
		}
	}
}

void ASpellPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation = FRotator(0.0f, Rotation.Yaw, 0.0f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.X);
	}
}

void ASpellPlayerController::ControllerJump()
{
	if(ACharacter* ControlledPawn = GetPawn<ACharacter>())
	{
		ControlledPawn->Jump();
	}
}

void ASpellPlayerController::ControllerStopJump()
{
	if(ACharacter* ControlledPawn = GetPawn<ACharacter>())
	{
		ControlledPawn->StopJumping();
	}
}



