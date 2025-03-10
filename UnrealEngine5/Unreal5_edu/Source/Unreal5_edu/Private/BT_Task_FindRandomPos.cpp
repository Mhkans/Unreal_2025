// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Task_FindRandomPos.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyAIController.h"

EBTNodeResult::Type UBT_Task_FindRandomPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type result = Super::ExecuteTask(OwnerComp, NodeMemory);
	auto currentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (currentPawn->IsValidLowLevel() == false) {
		return EBTNodeResult::Type::Failed;
	}
	FVector pos = currentPawn->GetActorLocation();

	//내가 움직일수있는 navMesh 찾기
	auto naviSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());

	if (naviSystem->IsValidLowLevel() == false) {
		return EBTNodeResult::Type::Failed;
	}
	FNavLocation randLocation;
	if (naviSystem->GetRandomPointInNavigableRadius(pos, 300.0f, randLocation)) {
		//뇌에 해당하는 ai 컨트롤러의 블랙보드 접근하기
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("RandPos")), randLocation.Location);
		return EBTNodeResult::Type::Succeeded;
	}

	return EBTNodeResult::Type::Failed;
}

void UBT_Task_FindRandomPos::OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult)
{
	Super::OnTaskFinished(OwnerComp, NodeMemory, TaskResult);
}
