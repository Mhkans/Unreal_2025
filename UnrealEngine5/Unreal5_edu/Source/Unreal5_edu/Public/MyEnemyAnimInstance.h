// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyEnemyAnimInstance.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE(FSendAttackerInfo);

UCLASS()
class UNREAL5_EDU_API UMyEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UMyEnemyAnimInstance();
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	UFUNCTION()
	void PlayAnimMontage_Attack();
	UFUNCTION()
	void PlayAnimMontage_Dead();
	UFUNCTION()
	void AnimNotify_Attack_Hit();
	UFUNCTION()
	void AnimNotify_Dead_Motion();
	FSendAttackerInfo OnSendAttackerInfo;
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimMontage", meta = (AllowprivateAccess = "true"))
	class UAnimMontage* _animMontage_Attack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimMontage", meta = (AllowprivateAccess = "true"))
	class UAnimMontage* _animMontage_Dead;
	UPROPERTY()
	class AMyEnemy* _enemy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move", meta = (AllowprivateAccess = "true"))
	float _speed = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move", meta = (AllowprivateAccess = "true"))
	bool _isFalling = false;
};
