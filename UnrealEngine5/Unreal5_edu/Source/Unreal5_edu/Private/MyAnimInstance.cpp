// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "MyCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Animation/AnimMontage.h"
UMyAnimInstance::UMyAnimInstance()
{

}

void UMyAnimInstance::PlayAnimMontage()
{
	if (_animMontage == nullptr) { return; }

	if (!Montage_IsPlaying(_animMontage))
	{
		_attackStart.Execute();
		_attackStart2.Execute(1, 2);
		_attackStart3.Broadcast(); //멀티캐스트
		Montage_Play(_animMontage);
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	auto pawn = TryGetPawnOwner();
	AMyCharacter* character = Cast<AMyCharacter>(pawn);
	if (character != nullptr) {
		_speed = character->GetVelocity().Size();
		_isFalling = character->GetMovementComponent()->IsFalling();
	}
}
