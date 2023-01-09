// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"

#include "SimpleRandomMovementProcessor.generated.h"

/**
 * 
 */
UCLASS()
class GTABASE_API USimpleRandomMovementProcessor : public UMassProcessor
{
	GENERATED_BODY()
	
public:
	USimpleRandomMovementProcessor();

protected:
	virtual void ConfigureQueries() override;
	virtual void Execute(struct FMassEntityManager& EntityManager, struct FMassExecutionContext& Context) override;

private:
	FMassEntityQuery EntityQuery;
};