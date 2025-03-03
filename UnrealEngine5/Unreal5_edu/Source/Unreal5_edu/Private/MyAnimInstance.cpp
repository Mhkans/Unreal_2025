// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayer.h"
#include "MyCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Animation/AnimMontage.h"
#include "MyAnimInstance.h"
UMyAnimInstance::UMyAnimInstance()
{

}

void UMyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	_player = Cast<AMyPlayer>(TryGetPawnOwner());
}

void UMyAnimInstance::PlayAnimMontage_Attack()
{
	if (_animMontage_Attack == nullptr) { return; }

	if (!Montage_IsPlaying(_animMontage_Attack))
	{
		//_attackStart.Execute();
		//_attackStart2.Execute(1, 2);
		//_attackStart3.Broadcast(); //멀티캐스트
		Montage_Play(_animMontage_Attack);
	}
}

void UMyAnimInstance::JumpToSection(int32 sectionIndex)
{
	FName sectionName = FName(*FString::Printf(TEXT("Section%d"), sectionIndex));
	Montage_JumpToSection(sectionName, _animMontage_Attack);
}

void UMyAnimInstance::AnimNotify_Attack_Hit()
{
	OnSendAttackerInfo.Broadcast();
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if (_player != nullptr) {
		_vertical = _player->My_Vertical();
		_horizontal = _player->My_Horizontal();
		_speed = _player->GetMovementComponent()->Velocity.Size2D();
		_isFalling = _player->GetMovementComponent()->IsFalling();
	}
}
