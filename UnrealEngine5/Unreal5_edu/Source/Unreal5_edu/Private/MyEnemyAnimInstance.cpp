// Fill out your copyright notice in the Description page of Project Settings.

#include "MyEnemy.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Animation/AnimMontage.h"
#include "MyEnemyAnimInstance.h"

UMyEnemyAnimInstance::UMyEnemyAnimInstance()
{
}

void UMyEnemyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	_enemy = Cast<AMyEnemy>(TryGetPawnOwner());
}

void UMyEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (_enemy != nullptr) {		
		_speed = _enemy->GetMovementComponent()->Velocity.Size2D();
		_isFalling = _enemy->GetMovementComponent()->IsFalling();
	}
}

void UMyEnemyAnimInstance::PlayAnimMontage_Attack()
{
	if (_animMontage_Attack == nullptr) { return; }

	if (!Montage_IsPlaying(_animMontage_Attack))
	{
		Montage_Play(_animMontage_Attack);
	}
}

void UMyEnemyAnimInstance::PlayAnimMontage_Dead()
{
	if (_animMontage_Dead == nullptr) { return; }

	if (!Montage_IsPlaying(_animMontage_Dead))
	{
		Montage_Play(_animMontage_Dead);
	}
}

void UMyEnemyAnimInstance::AnimNotify_Attack_Hit()
{
	OnSendAttackerInfo.Broadcast();
}

void UMyEnemyAnimInstance::AnimNotify_Dead_Motion()
{
	_enemy->SetActorHiddenInGame(true);
	_enemy->SetActorEnableCollision(false);
}
/*
ĳ����tick���� ü�� �����ϴ� 0�Ʒ��ζ������� �ִ��ν��Ͻ������ε��ص� �����ǽ���
�����ǽ���Ǹ� ��Ƽ�����ص� �������� ������� 
*/