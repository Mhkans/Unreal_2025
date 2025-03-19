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
#include "MyPlayerController.h"
#include "Components/Button.h"
#include "MyProjectile.h"
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
	auto invenUI = Cast<UMyInvenUI>(_invenWidget);
	if (invenUI) {
		invenUI->SetComponenet(CreateDefaultSubobject<UMyInvenComponent>(TEXT("InvenComponent")));
		invenUI->Drop->OnClicked.AddDynamic(this, &AMyPlayer::Drop_Button);
		invenUI->GetComponent()->itemAddEvent.AddUObject(invenUI, &UMyInvenUI::SetItem_Index);
		invenUI->GetComponent()->itemDropEvent.AddUObject(invenUI, &UMyInvenUI::SetItem_Default);
	}
}

void AMyPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	_animInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());		
	_animInstance->OnSendAttackerInfo.AddUObject(this, &AMyPlayer::Attack_Hit);		
	_animInstance->OnMontageEnded.AddDynamic(this, &AMyPlayer::AttackEnd);
	_animInstance->_deadEvent.AddUObject(this, &AMyPlayer::DeadEvent);

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
		enhancedInputComponent->BindAction(_dropAction, ETriggerEvent::Started, this, &AMyPlayer::Drop);
		enhancedInputComponent->BindAction(_invenAction, ETriggerEvent::Started, this, &AMyPlayer::InvenOpen);
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
	if (_isInvenOpen) { return; }
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

	auto projectile = GetWorld()->SpawnActor<AMyProjectile>(_projectileClass.Get(),GetActorLocation() + GetActorForwardVector() * 100.0f, GetActorRotation());

	projectile->FireDirection(GetActorForwardVector());


}

void AMyPlayer::Drop(const FInputActionValue& value)
{
	if (_isAttack) { return; }
	if (GetArraySize() <= 0) {
		return;
	}
	auto inven = Cast<UMyInvenUI>(_invenWidget);
	bool isPressed = value.Get<bool>();
	if (Controller != nullptr && isPressed) {
		if (inven) {
			auto item = inven->DropItem();
			FVector spawnLocation = SpawnItemPos();
			item->SetActorLocation(spawnLocation);
			item->SetActorHiddenInGame(false);
			item->SetActorEnableCollision(true);
		}
	}
}

void AMyPlayer::InvenOpen(const FInputActionValue& value)
{

	bool isPressed = value.Get<bool>();
	if (Controller != nullptr && isPressed) {
		auto controller = Cast<AMyPlayerController>(GetController());
		
		if (_isInvenOpen) {
			if (controller) {
				controller->HideUI();
			}
			_invenWidget->RemoveFromViewport();
		}
		else {
			if (controller) {
				controller->ShowUI();
			}
			_invenWidget->AddToViewport();
		}
		_isInvenOpen = !_isInvenOpen;

	}
}

void AMyPlayer::AddItem(AMyItem* item)
{
	auto inven = Cast<UMyInvenUI>(_invenWidget);
	if (item && inven) {
		inven->AddItem(item);
	}
}

FVector AMyPlayer::SpawnItemPos()
{
	FVector playerPos = GetActorLocation();

	float minDistance = 100.0f;
	float maxDistance = 300.0f;

	float SpawnDistance = FMath::RandRange(minDistance, maxDistance);
	float SpawnAngle = FMath::RandRange(0.0f, 360.0f);

	FVector itemPos;
	itemPos.X = playerPos.X + SpawnDistance * FMath::Cos(FMath::DegreesToRadians(SpawnAngle));
	itemPos.Y = playerPos.Y + SpawnDistance * FMath::Sin(FMath::DegreesToRadians(SpawnAngle));
	itemPos.Z = 0;

	return itemPos;

}

int32 AMyPlayer::GetArraySize()
{	
	auto inven = Cast<UMyInvenUI>(_invenWidget);
	return inven->GetArraySize();
}

void AMyPlayer::Drop_Button()
{
	if (_isAttack) { return; }
	if (GetArraySize() <= 0) {
		return;
	}
	auto inven = Cast<UMyInvenUI>(_invenWidget);
	if (inven) {
		auto item = inven->DropItem();
		FVector spawnLocation = SpawnItemPos();
		item->SetActorLocation(spawnLocation);
		item->SetActorHiddenInGame(false);
		item->SetActorEnableCollision(true);
	}
}


