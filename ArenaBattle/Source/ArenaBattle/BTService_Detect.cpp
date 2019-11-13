// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_Detect.h"
#include "ABAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "DrawDebugHelpers.h"


UBTService_Detect::UBTService_Detect()
{

}

void UBTService_Detect::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto Center = ControllingPawn->GetActorLocation();
	auto World = ControllingPawn->GetWorld();
	float DetectRadius = 600.0f;

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQuerParams(NAME_None, false, ControllingPawn);

	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(DetectRadius),
		CollisionQuerParams
	);

	DrawDebugSphere(World, Center, DetectRadius, 16, bResult ? FColor::Green : FColor::Red, false, 0.2f);
}
