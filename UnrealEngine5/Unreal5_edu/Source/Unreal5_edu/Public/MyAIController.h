// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL5_EDU_API AMyAIController : public AAIController
{
	GENERATED_BODY()
public:
	AMyAIController();

	virtual void OnPossess(APawn* InPawn) override; //컨트롤러가 pawn에 빙의될때 호출되는 함수
	virtual void OnUnPossess() override; //컨트롤러가 pawn에서 빙의가 해제될때 호출되는 함수

	UFUNCTION()
	void RandMove();

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	class UBlackboardData* _blackBoard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBehaviorTree* _behaviorTree;
private:
	UPROPERTY()
	FTimerHandle _timerHandle;
};
