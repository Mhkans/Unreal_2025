// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Service_FindTarget.h"
#include "MyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Engine/OverlapResult.h"
#include "DrawDebugHelpers.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"

#include"MyPlayer.h"
void UBT_Service_FindTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	auto currentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (currentPawn->IsValidLowLevel() == false) {
		return ;
	}
	FVector pos = currentPawn->GetActorLocation();
	float radius = 1000.0f;
	TArray<FOverlapResult> overlapResults;
	FCollisionQueryParams qParams(NAME_None, false, currentPawn);

	bool result = GetWorld()->OverlapMultiByChannel(overlapResults,
		pos,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(radius),
		qParams
	);

	if (!result) {
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Player")), nullptr);
		DrawDebugSphere(GetWorld(), pos, radius, 30, FColor::Green, false, 0.3f);
		return;
	}
	else {
		for (auto& col : overlapResults) {
			auto player = Cast<AMyPlayer>(col.GetActor());

			if (player->IsValidLowLevel()) {
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Player")), player);
				DrawDebugSphere(GetWorld(), pos, radius, 30, FColor::Red, false, 0.3f);
				return;
			}
		}
	}
}
