// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDecalActor.h"
#include "MyGameInstance.h"
#include "MyEffectManager.h"
AMyDecalActor::AMyDecalActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyDecalActor::BeginPlay()
{
	Super::BeginPlay();
	_runTime = 0.0f;
	
	//_endEvent.AddUObject(this, &AMyDecalActor::DeActivateEvent);

	//_endEvent.AddLambda([this]() {EFFECT_M->PlayEffect("BigFire", this->GetActorLocation()); });
}

void AMyDecalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!_bIsPlay) {
		return;
	}

	_runTime += DeltaTime;

	FVector curScale = GetActorScale();

	if (_runTime > _delayTime) {

		//if (_endEvent.IsBound()) {
		//	_endEvent.Broadcast();
		//}
		curScale.Y = 0.0f;
		curScale.Z = 0.0f;

		SetActorScale3D(curScale);

		if (_bLoop) {
			_runTime = 0.0f;
			_bIsPlay = true;
		}

		return;
		
		
	}
	curScale.Y = (_runTime / _delayTime) * _areaRadius;
	curScale.Z = (_runTime / _delayTime) * _areaRadius;

	SetActorScale3D(curScale);

}

void AMyDecalActor::Play(FVector pos)
{
	_bIsPlay = true;
	SetActorLocation(pos);
}

void AMyDecalActor::DeActivateEvent()
{
	_bIsPlay = false;
}
