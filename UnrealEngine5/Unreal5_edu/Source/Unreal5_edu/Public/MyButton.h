// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "MyButton.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL5_EDU_API UMyButton : public UButton
{
	GENERATED_BODY()
public:
	UFUNCTION()
	void SetCurIndex();

	virtual void PostLoad() override;
	class UMyInvenUI* widget;
	int32 _curIndex;
};
