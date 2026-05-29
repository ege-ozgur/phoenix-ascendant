#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthDeathSignature);

UENUM(BlueprintType)
enum class EPowerType : uint8
{
	Fire    UMETA(DisplayName = "Fire"),
	Light   UMETA(DisplayName = "Light")
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PHOENIXASCENDANT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	EPowerType WeakAgainst = EPowerType::Light;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void ApplyDamage(float DamageAmount, EPowerType DamageType);

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthDeathSignature OnDeath;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

protected:
	virtual void BeginPlay() override;
};