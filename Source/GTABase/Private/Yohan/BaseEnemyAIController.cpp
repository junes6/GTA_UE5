// Fill out your copyright notice in the Description page of Project Settings.


#include "Yohan/BaseEnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

ABaseEnemyAIController::ABaseEnemyAIController()
{
	// BehaviorTree Component 积己
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));

	// Blackboard Component 积己
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));

	// Behavior Tree 且寸(?)
	ConstructorHelpers::FObjectFinder<UBehaviorTree> BTEnemy(TEXT("/Script/AIModule.BehaviorTree'/Game/Yohan/AI/Enemy/BT_BaseEnemy.BT_BaseEnemy'"));
	// this->RunBehaviorTree(BTEnemy.Object);

	BehaviorTree = BTEnemy.Object;

}

void ABaseEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(BehaviorTree))
	{
		RunBehaviorTree(BehaviorTree);
		BehaviorTreeComponent->StartTree(*BehaviorTree);
	}


}

void ABaseEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (IsValid(Blackboard) && IsValid(BehaviorTree))
	{
		Blackboard->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	}
}
