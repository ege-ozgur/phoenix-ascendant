#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false; 
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth; 
}

void UHealthComponent::ApplyDamage(float DamageAmount, EPowerType DamageType)
{
	if (DamageAmount <= 0.0f || CurrentHealth <= 0.0f) {
		return;
	}

	// correct power double the damage, wrong power half the damage
	float Multiplier = (DamageType == WeakAgainst) ? 2.0f : 0.5f;
	float FinalDamage = DamageAmount * Multiplier;

	CurrentHealth = FMath::Clamp(CurrentHealth - FinalDamage, 0.0f, MaxHealth);

	UE_LOG(LogTemp, Warning, TEXT("Health: %f (took %f damage)"), CurrentHealth, FinalDamage);

	if (CurrentHealth <= 0.0f) {
		OnDeath.Broadcast();
	}
}

float UHealthComponent::GetHealthPercent() const{
	return (MaxHealth > 0.0f) ? (CurrentHealth / MaxHealth) : 0.0f;
}

void UHealthComponent::Heal(float Amount){
	if (Amount <= 0.0f || CurrentHealth <= 0.0f) {
		return;
	}
	CurrentHealth = FMath::Clamp(CurrentHealth + Amount, 0.0f, MaxHealth);
}