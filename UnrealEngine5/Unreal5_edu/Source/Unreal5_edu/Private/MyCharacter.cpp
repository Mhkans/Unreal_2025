// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "MyAnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine/DamageEvents.h"
#include "MyStatComponent.h"
#include "MyItem.h"
#include "Components/WidgetComponent.h"
#include "MyHPBar.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//블루프린트에서 스켈레탈메시
	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -88), FRotator(0, -90, 0));
	_springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	_springArm->SetupAttachment(GetCapsuleComponent());
	_camera->SetupAttachment(_springArm);

	_springArm->TargetArmLength = 500.0f;
	_springArm->SetRelativeRotation(FRotator(-35, 0, 0));

	_statComponent = CreateDefaultSubobject<UMyStatComponent>(TEXT("Stat"));

	_HPWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBar"));
	_HPWidget->SetupAttachment(GetMesh());
	_HPWidget->SetWidgetSpace(EWidgetSpace::World);

	static ConstructorHelpers::FClassFinder<UMyHPBar> hpBarClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrints/BP_MyHBBar.BP_MyHBBar_C'"));
	if (hpBarClass.Succeeded()) {
		_HPWidget->SetWidgetClass(hpBarClass.Class);
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	_animInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());

	//_animInstance->_attackStart.BindUObject(this, &AMyCharacter::TestDelegate);
	//_animInstance->_attackStart2.BindUObject(this, &AMyCharacter::TestDelegate2);
	//_animInstance->_attackStart3.AddDynamic(this, &AMyCharacter::TestDelegate);
	_animInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::AttackEnd);
	_animInstance->_info.AddUObject(this, &AMyCharacter::Attack_Hit);
	//_animInstance->_info.Remove();

	auto HPBar = Cast<UMyHPBar>(_HPWidget->GetWidget());
	if (HPBar) {
		_statComponent->_hpChanged.AddUObject(HPBar, &UMyHPBar::SetHpBarValue);
	}

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto playerCamera = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
	if (playerCamera) {
		FVector hpBarLocation = _HPWidget->GetComponentLocation();
		FVector cameraLocation = playerCamera->GetCameraLocation();
		FRotator rot = UKismetMathLibrary::FindLookAtRotation(hpBarLocation, cameraLocation);
		_HPWidget->SetWorldRotation(rot);
	}
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
			FVector forWard = GetActorForwardVector();
			FVector right = GetActorRightVector();
			
			_vertical = moveVector.Y;
			_horizontal = moveVector.X;

			AddMovementInput(forWard, moveVector.Y* _statComponent->GetSpeed());
			AddMovementInput(right, moveVector.X * _statComponent->GetSpeed());
		}
	}
}

void AMyCharacter::Look(const FInputActionValue& value)
{
	FVector2D lookAxisVector = value.Get<FVector2D>();
	if (Controller != nullptr) {
		AddControllerYawInput(lookAxisVector.X);
		AddControllerPitchInput(-lookAxisVector.Y);
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
		_curAttackSection = (_curAttackSection) % 3 + 1;
		_animInstance->PlayAnimMontage();
		_animInstance->JumpToSection(_curAttackSection);
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

void AMyCharacter::Attack_Hit()
{
	FHitResult hitResult;
	FCollisionQueryParams params(NAME_None, false, this);

	FVector forward = GetActorForwardVector();
	FQuat quat = FQuat::FindBetweenVectors(FVector(0, 0, 1), forward);//두 벡터 사이의 최단회전을 반환

	float attackRange = 500.0f;
	float attackRadius = 100.0f;

	//start 에서 end까지 쓸고 지나가는 형태의 충돌 판정
	FVector Center = GetActorLocation() + forward * attackRange * 0.5f; //바라보는 방향의 중심설정
	FVector Start = GetActorLocation() + forward * attackRange * 0.5f; //충돌체의 중심 start
	FVector End = GetActorLocation() + forward * attackRange * 0.5f; //충돌체의 중심 end

	bool bResult = GetWorld()->SweepSingleByChannel(
		OUT hitResult,
		Start,
		End,
		quat,
		ECC_GameTraceChannel2,
		FCollisionShape::MakeCapsule(attackRadius, attackRange *0.5f),
		params
	);

	FColor drawColor = FColor::Green;

	if (bResult && hitResult.GetActor()->IsValidLowLevel())
	{
		drawColor = FColor::Red;
		AMyCharacter* victim = Cast<AMyCharacter>(hitResult.GetActor());
		if (victim) {
			FDamageEvent damageEvent;
			victim->TakeDamage(_statComponent->GetAtk(), damageEvent, GetController(), this);
		}
	}

	DrawDebugCapsule(
		GetWorld(),
		Center,
		attackRange * 0.5f,
		attackRadius,
		quat,
		drawColor,
		false,
		3.0f
	);
	
}

float AMyCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	//방어력 다 깎고 실제입을 데미지 반환
	_statComponent->AddCurHp(-Damage);
	
	return Damage;
}

void AMyCharacter::AddHp(float amount)
{
	_statComponent->AddCurHp(amount);
}

