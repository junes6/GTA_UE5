// Fill out your copyright notice in the Description page of Project Settings.


#include "Yohan/EnemyBTTask_FindTargetLocation.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "AI/Navigation/NavigationTypes.h"
#include "BehaviorTree/BlackboardComponent.h"
// #include "Blueprint/AIBlueprintHelperLibrary.h"

UEnemyBTTask_FindTargetLocation::UEnemyBTTask_FindTargetLocation()
{
	NodeName = TEXT("Find Target Location");

	// Accept only vectors
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UEnemyBTTask_FindTargetLocation, BlackboardKey));
}

EBTNodeResult::Type UEnemyBTTask_FindTargetLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{	
	FNavLocation Location{};

	// Get AI Pawn
	AAIController* AIController = OwnerComp.GetAIOwner();
	const APawn* AIPawn = AIController->GetPawn();

	// Get Pawn origin
	const FVector Origin = AIPawn->GetActorLocation();

	// Obtain Navigation System and find a target location
	const UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (IsValid(NavSystem) && NavSystem->GetRandomReachablePointInRadius(Origin, SearchRadius, Location))
	{
		AIController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, Location.Location);
	}

	// Signal the BehaviorTreeComponent that the task finished with a Success
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

FString UEnemyBTTask_FindTargetLocation::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector: %s"), *BlackboardKey.SelectedKeyName.ToString());
}
