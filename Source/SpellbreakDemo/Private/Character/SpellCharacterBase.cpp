


#include "Character/SpellCharacterBase.h"

#include "NavigationSystemTypes.h"

ASpellCharacterBase::ASpellCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	GauntletWeapon1 = CreateDefaultSubobject<USkeletalMeshComponent>("RightGauntlet");
	GauntletWeapon1->SetupAttachment(GetMesh(), FName("RightHandGauntletSocket"));
	GauntletWeapon1->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	GauntletWeapon2 = CreateDefaultSubobject<USkeletalMeshComponent>("LeftGauntlet");	
	GauntletWeapon2->SetupAttachment(GetMesh(), FName("LeftHandGauntletSocket"));
	GauntletWeapon2->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* ASpellCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASpellCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



