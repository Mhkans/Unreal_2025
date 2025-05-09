// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "MyEnemy.generated.h"

/**
 * 
 */

//DECLARE_MULTICAST_DELEGATE()

UCLASS()
class UNREAL5_EDU_API AMyEnemy : public AMyCharacter
{
	GENERATED_BODY()
	
public:
	AMyEnemy();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void PlayDeadMotion();

public:
	void Attack_AI();
	
private:
	UPROPERTY()
	class UMyEnemyAnimInstance* _animInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowprivateAccess = "true"))
	class UWidgetComponent* _HPWidget;
};
