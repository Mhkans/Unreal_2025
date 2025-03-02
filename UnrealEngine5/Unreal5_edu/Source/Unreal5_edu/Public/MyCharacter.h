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

public:		
	void Attack_Hit();
	void AttackEnd(class UAnimMontage* montage, bool bInterrupted);

	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void AddHp(float amount);
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation", meta = (AllowprivateAccess = "true"))
	bool _isAttack = false;

	UPROPERTY()
	class UMyAnimInstance* _animInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat", meta = (AllowprivateAccess = "true"))
	class UMyStatComponent* _statComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowprivateAccess = "true"))
	class UWidgetComponent* _HPWidget;

};
