// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include"MyAnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//�������Ʈ���� ���̷�Ż�޽�
	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -88), FRotator(0, -90, 0));
	_springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	_springArm->SetupAttachment(GetCapsuleComponent());
	_camera->SetupAttachment(_springArm);

	_springArm->TargetArmLength = 500.0f;
	_springArm->SetRelativeRotation(FRotator(-35, 0, 0));
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	_animInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());

	_animInstance->_attackStart.BindUObject(this, &AMyCharacter::TestDelegate);
	_animInstance->_attackStart2.BindUObject(this, &AMyCharacter::TestDelegate2);
	_animInstance->_attackStart3.AddDynamic(this, &AMyCharacter::TestDelegate);
	_animInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::AttackEnd);
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhancedInputComponent) {
		enhancedInputComponent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
		enhancedInputComponent->BindAction(_lookAction, ETriggerEvent::Triggered, this, &AMyCharacter::Look);
		enhancedInputComponent->BindAction(_jumpAction, ETriggerEvent::Triggered, this, &AMyCharacter::JumpA);
		enhancedInputComponent->BindAction(_attackAction, ETriggerEvent::Triggered, this, &AMyCharacter::Attack);
	}
}

void AMyCharacter::Move(const FInputActionValue& value)
{
	if (_isAttack) { return; }
	FVector2D moveVector = value.Get<FVector2D>();
	if (Controller != nullptr) {
		if (moveVector.Length() > 0.01f) {
			//UE_LOG(LogTemp, Error, TEXT("Y : %f"), moveVector.Y);
			//UE_LOG(LogTemp, Error, TEXT("X : %f"), moveVector.X);

			FVector forWard = GetActorForwardVector();
			FVector right = GetActorRightVector();
			
			AddMovementInput(forWard, moveVector.Y* _moveSpeed);
			AddMovementInput(right, moveVector.X *_moveSpeed);
		}
	}
}

void AMyCharacter::Look(const FInputActionValue& value)
{
	FVector2D lookAxisVector = value.Get<FVector2D>();
	if (Controller != nullptr) {
		AddControllerYawInput(lookAxisVector.X);
	}
}

void AMyCharacter::JumpA(const FInputActionValue& value)
{
	if (_isAttack) { return; }
	bool isPressed = value.Get<bool>();
	if (Controller != nullptr && isPressed) {
		ACharacter::Jump();
	}
}

void AMyCharacter::Attack(const FInputActionValue& value)
{
	if (_isAttack) { return; }
	bool isPressed= value.Get<bool>();
	if (Controller != nullptr && isPressed) {
		_isAttack = true;
		_animInstance->PlayAnimMontage();
		/*auto animInstance = GetMesh()->GetAnimInstance();
		auto myAnimInstance = Cast<UMyAnimInstance>(animInstance);
		if (myAnimInstance != nullptr) {
			myAnimInstance->PlayAnimMontage();
		}*/
	}
}

void AMyCharacter::TestDelegate()
{
	UE_LOG(LogTemp, Error, TEXT("ATTACK start delegate test"));
}

int32 AMyCharacter::TestDelegate2(int32 a, int32 b)
{
	UE_LOG(LogTemp, Error, TEXT("ATTACK start delegate test 2 ,%d,%d"),a,b);
	return -1;
}

void AMyCharacter::AttackEnd(UAnimMontage* montage, bool bInterrupted)
{
	_isAttack = false;
}

