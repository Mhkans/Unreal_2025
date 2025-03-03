// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStatComponent.h"
#include "MyCharacter.h"
#include "MyGameInstance.h"
// Sets default values for this component's properties
UMyStatComponent::UMyStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	
}


// Called when the game starts
void UMyStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	auto gameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());	
	auto character = Cast<AMyCharacter>(GetOwner());
	_level = character->GetLevel();
	auto statInfo = gameInstance->GetStat_Level(_level);
	_maxHp = statInfo.hp;
	_curHp = statInfo.hp;
	_atk = statInfo.atk;
	_EXP = statInfo.EXP;
	_maxEXP = statInfo.maxEXP;
	_curEXP = 0;
}


// Called every frame
void UMyStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 UMyStatComponent::AddCurHp(float amount)
{
	int32 before = _curHp;

	_curHp += amount;
	if (_curHp <= 0) {
		PlayDeadMotion.Broadcast();
		_curHp = 0;
	}
	if (_curHp > _maxHp) {
		_curHp = _maxHp;
	}
	auto actor = GetOwner();

	UE_LOG(LogTemp, Warning, TEXT("Vic Name : %s , HP : %d"), *actor->GetName(), _curHp);

	float ratio = _curHp / (float)_maxHp;
	if (_hpChanged.IsBound()) {
		_hpChanged.Broadcast(ratio);
	}
	
	return before - _curHp;
}

void UMyStatComponent::AddEXP(int32 value)
{
	UE_LOG(LogTemp, Error, TEXT("LEVEL: %d"), _level);
	UE_LOG(LogTemp, Warning, TEXT("Required EXP : %d "), _maxEXP - _curEXP);
	UE_LOG(LogTemp, Warning, TEXT("Current EXP : %d "), _curEXP);

	_curEXP += value;
	UE_LOG(LogTemp, Warning, TEXT("Current EXP : %d  , PLUS EXP : %d"), _curEXP , value);

	if (_curEXP >= _maxEXP) {
		auto exp = _curEXP - _maxEXP;
		_level++;
		UE_LOG(LogTemp, Error, TEXT("LEVEL changed : %d"),_level);

		auto gameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
		auto statInfo = gameInstance->GetStat_Level(_level);
		_maxHp = statInfo.hp;
		_curHp = statInfo.hp;
		_atk = statInfo.atk;
		_EXP = statInfo.EXP;
		_maxEXP = statInfo.maxEXP;
		_curEXP = exp;
	}
}

