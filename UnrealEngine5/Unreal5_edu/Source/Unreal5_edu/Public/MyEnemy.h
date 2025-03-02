// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "MyEnemy.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL5_EDU_API AMyEnemy : public AMyCharacter
{
	GENERATED_BODY()
	
public:
	AMyEnemy();

private:
	virtual void BeginPlay() override;

public:

private:

};
