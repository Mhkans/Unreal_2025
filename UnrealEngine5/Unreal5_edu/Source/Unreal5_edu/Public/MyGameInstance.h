// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyStatComponent.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
#define EFFECT_M Cast<UMyGameInstance>(GetGameInstance())->EffectManager()
UCLASS()
class UNREAL5_EDU_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UMyGameInstance();
	virtual void Init() override;

	FMyStatData GetStat_Level(int32 level);
	class AMyEffectManager* EffectManager() { return _effectManager; }

private:
	UPROPERTY()
	class UDataTable* _statTable;
	UPROPERTY()
	class AMyEffectManager* _effectManager;
};
