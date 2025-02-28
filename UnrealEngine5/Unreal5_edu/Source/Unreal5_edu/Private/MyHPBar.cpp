// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHPBar.h"
#include "Components/ProgressBar.h"

void UMyHPBar::SetHpBarValue(float ratio)
{
	PB_HPBar->SetPercent(ratio);
}
