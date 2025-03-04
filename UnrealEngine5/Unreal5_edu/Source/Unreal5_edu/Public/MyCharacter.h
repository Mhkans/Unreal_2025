// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class UNREAL5_EDU_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void TakeEXP(AMyCharacter* victim);
public:		
	virtual void Attack_Hit();
	void DeadEvent();
	UFUNCTION()
	void AttackEnd(class UAnimMontage* montage, bool bInterrupted);

	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void AddHp(float amount);
	const int16& GetLevel() { return _level; }

	bool IsDead();
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation", meta = (AllowprivateAccess = "true"))
	bool _isAttack = false;

	UPROPERTY()
	int16 _level;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat", meta = (AllowprivateAccess = "true"))
	class UMyStatComponent* _statComponent;


};
