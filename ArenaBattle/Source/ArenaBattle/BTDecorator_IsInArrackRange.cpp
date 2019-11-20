// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsInArrackRange.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ABAIController.h"
#include "ABCharacter.h"

UBTDecorator_IsInArrackRange::UBTDecorator_IsInArrackRange()
{
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_IsInArrackRange::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();

	if (nullptr == ControllingPawn)
		return false;

	auto Target = Cast<AABCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Target"))));

	if (nullptr == Target)
		return false;

	bResult = (Target->GetDistanceTo(ControllingPawn) <= 200.0f);

	return bResult;
}
