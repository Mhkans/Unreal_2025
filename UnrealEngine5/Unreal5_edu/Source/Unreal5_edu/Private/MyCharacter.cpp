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

	_statComponent = CreateDefaultSubobject<UMyStatComponent>(TEXT("Stat"));

	_HPWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBar"));
	_HPWidget->SetupAttachment(GetMesh());
	_HPWidget->SetWidgetSpace(EWidgetSpace::Screen);
	_HPWidget->SetRelativeLocation(FVector(0, 0, 250));

	static ConstructorHelpers::FClassFinder<UMyHPBar> hpBarClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrints/BP_MyHBBar.BP_MyHBBar_C'"));
	if (hpBarClass.Succeeded()) {
		_HPWidget->SetWidgetClass(hpBarClass.Class);
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	auto HPBar = Cast<UMyHPBar>(_HPWidget->GetUserWidgetObject());
	if (HPBar) {
		_statComponent->_hpChanged.AddUObject(HPBar, &UMyHPBar::SetHpBarValue);
	}
	
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

void AMyCharacter::AttackEnd(UAnimMontage* montage, bool bInterrupted)
{
	_isAttack = false;
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

