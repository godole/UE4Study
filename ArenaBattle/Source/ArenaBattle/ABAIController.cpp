// Fill out your copyright notice in the Description page of Project Settings.


#include "ABAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

AABAIController::AABAIController()
{
	//BlackboardData'/Game/Book/AI/BB_ABCharacter.BB_ABCharacter'
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/Book/AI/BB_ABCharacter.BB_ABCharacter"));
	if (BBObject.Succeeded())
		BBAsset = BBObject.Object;

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/Book/AI/BT_ABCharacter.BT_ABCharacter"));
	if (BTObject.Succeeded())
		BTAsset = BTObject.Object;
}

void AABAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (UseBlackboard(BBAsset, Blackboard))
	{
		Blackboard->SetValueAsFloat(FName("Timer"), 5.0f);
		Blackboard->SetValueAsFloat(FName("Radius"), 500.0f);
		Blackboard->SetValueAsVector(FName("StartPosition"), GetPawn()->GetActorLocation());
		RunBehaviorTree(BTAsset);
	}
}

void AABAIController::OnUnPossess()
{
	Super::OnUnPossess();
}
