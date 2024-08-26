


#include "Actor/SpellEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/SpellAttributeSet.h"
#include "Components/SphereComponent.h"

ASpellEffectActor::ASpellEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void ASpellEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a gameplay effect. For now, using const cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const USpellAttributeSet* SpellAttributeSet = Cast<USpellAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(USpellAttributeSet::StaticClass()));
		USpellAttributeSet* MutableSpellAttributeSet = const_cast<USpellAttributeSet*>(SpellAttributeSet);
		MutableSpellAttributeSet->SetHealth(SpellAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void ASpellEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void ASpellEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ASpellEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ASpellEffectActor::EndOverlap);
}
