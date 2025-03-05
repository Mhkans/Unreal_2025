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
#include "MyPlayer.h"
#include "Blueprint/UserWidget.h"
#include "MyInvenUI.h"
#include "MyInvenComponent.h"
AMyPlayer::AMyPlayer()
{
	_level = 3;

	_springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	_springArm->SetupAttachment(GetCapsuleComponent());
	_camera->SetupAttachment(_springArm);

	_springArm->TargetArmLength = 500.0f;
	_springArm->SetRelativeRotation(FRotator(-35, 0, 0));
	_springArm->SetRelativeLocation(FVector(-50, 0, 88));
	
	static ConstructorHelpers::FClassFinder<UMyInvenUI> invenClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrints/BP_MyInvenUI.BP_MyInvenUI_C'"));
	if (invenClass.Succeeded()) {
		_invenWidget = CreateWidget<UUserWidget>(GetWorld(),invenClass.Class);
	}

	_invenComponent = CreateDefaultSubobject<UMyInvenComponent>(TEXT("InvenComponent"));
	
}

void AMyPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	auto invenUI = Cast<UMyInvenUI>(_invenWidget);
	if (invenUI) {
		_invenComponent->itemAddEvent.AddUObject(invenUI, &UMyInvenUI::SetItem_Index);
	}
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	_animInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());		
	_animInstance->OnSendAttackerInfo.AddUObject(this, &AMyPlayer::Attack_Hit);		
	_animInstance->OnMontageEnded.AddDynamic(this, &AMyPlayer::AttackEnd);
	_animInstance->_deadEvent.AddUObject(this, &AMyPlayer::DeadEvent);

	if (_invenWidget) {
		_invenWidget->AddToViewport();
	}
}
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhancedInputComponent) {
		enhancedInputComponent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &AMyPlayer::Move);
		enhancedInputComponent->BindAction(_lookAction, ETriggerEvent::Triggered, this, &AMyPlayer::Look);
		enhancedInputComponent->BindAction(_jumpAction, ETriggerEvent::Triggered, this, &AMyPlayer::JumpA);
		enhancedInputComponent->BindAction(_attackAction, ETriggerEvent::Triggered, this, &AMyPlayer::Attack);
		enhancedInputComponent->BindAction(_dropAction, ETriggerEvent::Triggered, this, &AMyPlayer::Drop);

	}
}

void AMyPlayer::Move(const FInputActionValue& value)
{
	if (_isAttack) { return; }
	FVector2D moveVector = value.Get<FVector2D>();
	if (Controller != nullptr) {
		if (moveVector.Length() > 0.01f) {
			FVector forWard = GetActorForwardVector();
			FVector right = GetActorRightVector();

			_vertical = moveVector.Y;
			_horizontal = moveVector.X;

			AddMovementInput(forWard, moveVector.Y * _statComponent->GetSpeed());
			AddMovementInput(right, moveVector.X * _statComponent->GetSpeed());
		}
	}
}

void AMyPlayer::Look(const FInputActionValue& value)
{
	FVector2D lookAxisVector = value.Get<FVector2D>();
	if (Controller != nullptr) {
		AddControllerYawInput(lookAxisVector.X);
		AddControllerPitchInput(-lookAxisVector.Y);
	}
}

void AMyPlayer::JumpA(const FInputActionValue& value)
{
	if (_isAttack) { return; }
	bool isPressed = value.Get<bool>();
	if (Controller != nullptr && isPressed) {
		ACharacter::Jump();
	}
}

void AMyPlayer::Attack(const FInputActionValue& value)
{
	if (_isAttack) { return; }
	bool isPressed = value.Get<bool>();
	if (Controller != nullptr && isPressed) {
		_isAttack = true;
		_curAttackSection = (_curAttackSection) % 3 + 1;
		_animInstance->PlayAnimMontage_Attack();
		_animInstance->JumpToSection(_curAttackSection);
	}
}

void AMyPlayer::Drop(const FInputActionValue& value)
{

}

void AMyPlayer::AddItem(AMyItem* item)
{
	if (item && _invenComponent) {
		_invenComponent->AddItem(item->GetInfo().itemId, item->GetInfo().type);
	}
}

FVector AMyPlayer::SpawnItem()
{
	FVector playerPos = GetActorLocation();

	float minDistance = 100.0f;
	float maxDistance = 500.0f;

	float SpawnDistance = FMath::RandRange(minDistance, maxDistance);
	float SpawnAngle = FMath::RandRange(0.0f, 360.0f);

	FVector itemPos;
	itemPos.X = playerPos.X + SpawnDistance * FMath::Cos(FMath::DegreesToRadians(SpawnAngle));
	itemPos.Y = playerPos.Y + SpawnDistance * FMath::Sin(FMath::DegreesToRadians(SpawnAngle));
	itemPos.Z = playerPos.Z;

	return itemPos;

}


