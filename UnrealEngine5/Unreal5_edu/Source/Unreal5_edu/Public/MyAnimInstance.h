// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
//void(void) �ϳ���(�������Ʈ x)
DECLARE_DELEGATE(AnimDelegateTest);
//int(int,int) (�������Ʈ x)
DECLARE_DELEGATE_RetVal_TwoParams(int32, AnimDelegateTest2, int32, int32);

//���̳��� ��Ƽĳ��Ʈ delegate (�������Ʈ������������) ufuction�� �����͵鸸 ����
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnimDelegateTest3);



//

DECLARE_MULTICAST_DELEGATE(AttackerInfo);

UCLASS()
class UNREAL5_EDU_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UMyAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds);

	UFUNCTION()
	void PlayAnimMontage();
	UFUNCTION()
	void JumpToSection(int32 sectionIndex);


	UFUNCTION()
	void AnimNotify_Attack_Hit();

	AnimDelegateTest _attackStart;
	AnimDelegateTest2 _attackStart2;
	UPROPERTY()
	FAnimDelegateTest3 _attackStart3;

	AttackerInfo _info;
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn", meta = (AllowprivateAccess = "true"))
	float _speed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn", meta = (AllowprivateAccess = "true"))
	bool _isFalling = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimMontage", meta = (AllowprivateAccess = "true"))
	class UAnimMontage* _animMontage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimMontage", meta = (AllowprivateAccess = "true"))
	float _vertical;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimMontage", meta = (AllowprivateAccess = "true"))
	float _horizontal;
};
