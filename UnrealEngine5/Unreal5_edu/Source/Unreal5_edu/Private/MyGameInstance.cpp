// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "MyStatComponent.h"
#include "Engine/DataTable.h"
#include "MyEffectManager.h"
UMyGameInstance::UMyGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> dataTable(TEXT("/Script/Engine.DataTable'/Game/Data/MyDataTable.MyDataTable'"));

	if (dataTable.Succeeded()) {
		_statTable = dataTable.Object;
	}
}

void UMyGameInstance::Init()
{
	Super::Init();
	_effectManager = GetWorld()->SpawnActor<AMyEffectManager>(FVector::ZeroVector, FRotator::ZeroRotator);
}

FMyStatData UMyGameInstance::GetStat_Level(int32 level)
{
	FString LevelName = "Level_" + FString::FromInt(level);
	auto row = _statTable->FindRow<FMyStatData>(*LevelName, TEXT(""));
	return *row;
}
