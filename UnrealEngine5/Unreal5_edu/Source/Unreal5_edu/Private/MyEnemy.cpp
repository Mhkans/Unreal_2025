// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "MyAnimInstance.h"
#include "MyEnemyAnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine/DamageEvents.h"
#include "MyStatComponent.h"
#include "MyItem.h"
#include "Components/WidgetComponent.h"
#include "MyHPBar.h"
#include "MyEnemy.h"

AMyEnemy::AMyEnemy()
{
	_level = 2;
	_HPWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBar"));
	_HPWidget->SetupAttachment(GetMesh());
	_HPWidget->SetWidgetSpace(EWidgetSpace::Screen);
	_HPWidget->SetRelativeLocation(FVector(0, 0, 250));

	static ConstructorHelpers::FClassFinder<UMyHPBar> hpBarClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrints/BP_MyHBBar.BP_MyHBBar_C'"));
	if (hpBarClass.Succeeded()) {
		_HPWidget->SetWidgetClass(hpBarClass.Class);
	}
}

void AMyEnemy::BeginPlay()
{
	Super::BeginPlay();
	_animInstance = Cast<UMyEnemyAnimInstance>(GetMesh()->GetAnimInstance());
	_animInstance->OnSendAttackerInfo.AddUObject(this, &AMyEnemy::Attack_Hit);	
	_animInstance->OnMontageEnded.AddDynamic(this, &AMyEnemy::AttackEnd);
	_statComponent->PlayDeadMotion.AddUObject(this, &AMyEnemy::PlayDeadMotion);

	auto HPBar = Cast<UMyHPBar>(_HPWidget->GetUserWidgetObject());
	if (HPBar) {
		_statComponent->_hpChanged.AddUObject(HPBar, &UMyHPBar::SetHpBarValue);
	}

}

void AMyEnemy::Tick(float DeltaTime)
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

void AMyEnemy::PlayDeadMotion()
{
	_animInstance->PlayAnimMontage_Dead();
}




