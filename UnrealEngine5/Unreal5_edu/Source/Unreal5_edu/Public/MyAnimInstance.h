// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
//void(void) 하나만(블루프린트 x)
DECLARE_DELEGATE(AnimDelegateTest);
//int(int,int) (블루프린트 x)
DECLARE_DELEGATE_RetVal_TwoParams(int32, AnimDelegateTest2, int32, int32);

//다이나믹 멀티캐스트 delegate (블루프린트에서볼수있음) ufuction이 붙은것들만 가능
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnimDelegateTest3);



//

DECLARE_MULTICAST_DELEGATE(FSendAttackerInfo);

UCLASS()
class UNREAL5_EDU_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UMyAnimInstance();
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds);

	UFUNCTION()
	void PlayAnimMontage_Attack();
	UFUNCTION()
	void JumpToSection(int32 sectionIndex);


	UFUNCTION()
	void AnimNotify_Attack_Hit();

	AnimDelegateTest _attackStart;
	AnimDelegateTest2 _attackStart2;
	UPROPERTY()
	FAnimDelegateTest3 _attackStart3;
	FSendAttackerInfo OnSendAttackerInfo; 
private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimMontage", meta = (AllowprivateAccess = "true"))
	class UAnimMontage* _animMontage_Attack;
	
	UPROPERTY()
	class AMyPlayer* _player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimMontage", meta = (AllowprivateAccess = "true"))
	float _vertical;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimMontage", meta = (AllowprivateAccess = "true"))
	float _horizontal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move", meta = (AllowprivateAccess = "true"))
	float _speed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move", meta = (AllowprivateAccess = "true"))
	bool _isFalling = false;
};
