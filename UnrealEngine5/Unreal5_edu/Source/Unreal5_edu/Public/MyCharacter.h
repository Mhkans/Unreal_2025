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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	void Move(const struct FInputActionValue& value);
	UFUNCTION()
	void Look(const struct FInputActionValue& value);
	UFUNCTION()
	void JumpA(const struct FInputActionValue& value);
	UFUNCTION()
	void Attack(const struct FInputActionValue& value);

	UFUNCTION()
	void TestDelegate();
	UFUNCTION()
	int32 TestDelegate2(int32 a, int32 b);

	UFUNCTION()
	void AttackEnd(class UAnimMontage* montage, bool bInterrupted);

	float My_Vertical() { return _vertical; }
	float My_Horizontal() { return _horizontal; }
	
	UFUNCTION()
	void Attack_Hit();
private:
	UPROPERTY(EditAnywhere, Category = "Speed")
	float _moveSpeed = 10.0f;
	UPROPERTY(EditAnywhere, Category = "Speed")
	float _rotationSpeed = 30.0f;

	UPROPERTY(EditAnywhere, Category = "Speed")
	float _jumpSpeed = 1000.0f;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowprivateAccess = "true"))
	class UInputAction* _moveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowprivateAccess = "true"))
	class UInputAction* _lookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowprivateAccess = "true"))
	class UInputAction* _jumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack", meta = (AllowprivateAccess = "true"))
	class UInputAction* _attackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation", meta = (AllowprivateAccess = "true"))
	bool _isAttack = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowprivateAccess = "true"))
	class UCameraComponent* _camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowprivateAccess = "true"))
	class USpringArmComponent* _springArm;

	UPROPERTY()
	class UMyAnimInstance* _animInstance;

	int32 _curAttackSection = 1;

	float _vertical = 0.0f;
	float _horizontal = 0.0f;
	
};
