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
}

void AMyEnemy::BeginPlay()
{
	Super::BeginPlay();
	_animInstance = Cast<UMyEnemyAnimInstance>(GetMesh()->GetAnimInstance());
	_animInstance->OnSendAttackerInfo.AddUObject(this, &AMyEnemy::Attack_Hit);	
	_animInstance->OnMontageEnded.AddDynamic(this, &AMyEnemy::AttackEnd);
	_statComponent->PlayDeadMotion.AddUObject(this, &AMyEnemy::PlayDeadMotion);

}

void AMyEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AMyEnemy::PlayDeadMotion()
{
	_animInstance->PlayAnimMontage_Dead();
}




