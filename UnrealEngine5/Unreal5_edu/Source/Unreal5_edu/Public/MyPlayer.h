// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "MyPlayer.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL5_EDU_API AMyPlayer : public AMyCharacter
{
	GENERATED_BODY()
	
public:
	AMyPlayer();

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
	

	float My_Vertical() { return _vertical; }
	float My_Horizontal() { return _horizontal; }
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowprivateAccess = "true"))
	class UInputAction* _moveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowprivateAccess = "true"))
	class UInputAction* _lookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowprivateAccess = "true"))
	class UInputAction* _jumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack", meta = (AllowprivateAccess = "true"))
	class UInputAction* _attackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowprivateAccess = "true"))
	class UCameraComponent* _camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowprivateAccess = "true"))
	class USpringArmComponent* _springArm;
	UPROPERTY()
	class UMyAnimInstance* _animInstance;
private:
	int32 _curAttackSection = 1;

	float _vertical = 0.0f;
	float _horizontal = 0.0f;

};
