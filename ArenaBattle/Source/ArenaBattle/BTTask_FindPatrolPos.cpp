// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindPatrolPos.h"
#include "ABAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"


UBTTask_FindPatrolPos::UBTTask_FindPatrolPos()
{
	NodeName = TEXT("Set Destination");
}

EBTNodeResult::Type UBTTask_FindPatrolPos::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();

	if(nullptr == ControllingPawn)
		return EBTNodeResult::Type::Failed;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());

	if (nullptr == NavSystem)
		return EBTNodeResult::Type::Failed;

	//FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(FName("StartPosition"));
	FNavLocation NextPatrol;

	float radius = OwnerComp.GetBlackboardComponent()->GetValueAsFloat(FName("Radius"));
	if (NavSystem->GetRandomPointInNavigableRadius(ControllingPawn->GetActorLocation(), radius, NextPatrol))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("Destination"), NextPatrol.Location);
		return EBTNodeResult::Type::Succeeded;
	}

	return EBTNodeResult::Type::Failed;
}
