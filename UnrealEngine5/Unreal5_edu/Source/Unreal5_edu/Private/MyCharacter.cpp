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
#include "MyPlayerController.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//�������Ʈ���� ���̷�Ż�޽�
	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -88), FRotator(0, -90, 0));

	_statComponent = CreateDefaultSubobject<UMyStatComponent>(TEXT("Stat"));
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyCharacter::TakeEXP(AMyCharacter* victim)
{
	auto EXP = victim->_statComponent->GetEXP();
	_statComponent->AddEXP(EXP);
}

void AMyCharacter::Attack_Hit()
{
	FHitResult hitResult;
	FCollisionQueryParams params(NAME_None, false, this);

	FVector forward = GetActorForwardVector();
	FQuat quat = FQuat::FindBetweenVectors(FVector(0, 0, 1), forward);//�� ���� ������ �ִ�ȸ���� ��ȯ

	float attackRange = 500.0f;
	float attackRadius = 100.0f;

	//start ���� end���� ���� �������� ������ �浹 ����
	FVector Center = GetActorLocation() + forward * attackRange * 0.5f; //�ٶ󺸴� ������ �߽ɼ���
	FVector Start = GetActorLocation() + forward * attackRange * 0.5f; //�浹ü�� �߽� start
	FVector End = GetActorLocation() + forward * attackRange * 0.5f; //�浹ü�� �߽� end

	bool bResult = GetWorld()->SweepSingleByChannel( //��Ƽä�η� �����ص���
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
			UE_LOG(LogTemp, Warning, TEXT("Att Name : %s , HP : %d"), *GetName(), _statComponent->GetCurHp());

			victim->TakeDamage(_statComponent->GetAtk(), damageEvent, GetController(), this);
			if (victim->_statComponent->IsDead()) {
				TakeEXP(victim);
			}
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

void AMyCharacter::DeadEvent()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void AMyCharacter::AttackEnd(UAnimMontage* montage, bool bInterrupted)
{
	_isAttack = false;
}

float AMyCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	//���� �� ��� �������� ������ ��ȯ
	_statComponent->AddCurHp(-Damage);
	
	auto attackerController = Cast<AMyPlayerController>(EventInstigator);
	if (attackerController) {
		if (IsDead()) {
			UE_LOG(LogTemp, Error, TEXT("Dead by Player"));
		}
	}
	return Damage;
}

void AMyCharacter::AddHp(float amount)
{
	_statComponent->AddCurHp(amount);
}

bool AMyCharacter::IsDead()
{
	return _statComponent->IsDead();
}

