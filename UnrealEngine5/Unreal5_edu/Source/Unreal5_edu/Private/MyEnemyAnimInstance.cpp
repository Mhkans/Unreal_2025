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
캐릭터tick에서 체력 감시하다 0아래로떨어지면 애님인스턴스에바인딩해둔 데드모션실행
데드모션실행되면 노티파이해둔 지점에서 사라지게 
*/