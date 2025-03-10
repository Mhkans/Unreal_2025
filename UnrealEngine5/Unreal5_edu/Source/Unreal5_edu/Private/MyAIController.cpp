// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

AMyAIController::AMyAIController()
{
	
}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	//3초마다 RandMove함수 호출 , loop -> true
	//GetWorld()->GetTimerManager().SetTimer(_timerHandle, this, &AMyAIController::RandMove, 1.0f, true);
	UBlackboardComponent* temp = Blackboard;
	if (UseBlackboard(_blackBoard, temp)) {
		if (RunBehaviorTree(_behaviorTree)) {

		}
		else {

		}
	}
	else {

	}
}

void AMyAIController::OnUnPossess()
{
	Super::OnUnPossess();

	//GetWorld()->GetTimerManager().ClearTimer(_timerHandle);
	
}

void AMyAIController::RandMove()
{
	auto curPawn = GetPawn(); //현재 빙의되어있는 폰
	if (curPawn->IsValidLowLevel() == false) {
		return;
	}
	
	auto navMesh = UNavigationSystemV1::GetNavigationSystem(GetWorld()); //설정한 navMesh를 갖고옴
	if (navMesh->IsValidLowLevel() == false) {
		return;
	}

	FNavLocation randLocation;
	FVector pawnLocation = curPawn->GetActorLocation();
	if (navMesh->GetRandomPointInNavigableRadius(pawnLocation, 300.0f, randLocation)) {

		//randLocation에 랜덤좌표가 들어갔음
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, randLocation.Location);
	}
}
