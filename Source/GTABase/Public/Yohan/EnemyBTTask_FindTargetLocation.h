// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EnemyBTTask_FindTargetLocation.generated.h"

/**
 * 
 */
UCLASS()
class GTABASE_API UEnemyBTTask_FindTargetLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UEnemyBTTask_FindTargetLocation();

private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual FString GetStaticDescription() const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search", meta = (AllowPrivateAccess = true))
	float SearchRadius { 500.f };
};
