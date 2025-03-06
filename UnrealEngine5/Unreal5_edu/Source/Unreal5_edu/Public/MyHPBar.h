// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyHPBar.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL5_EDU_API UMyHPBar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetHpBarValue(float ratio);
private:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* PB_HPBar; //반드시 이름을 맞춰줘야함
};
