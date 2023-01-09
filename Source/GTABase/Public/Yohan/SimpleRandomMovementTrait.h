// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "MassEntityTypes.h"

#include "SimpleRandomMovementTrait.generated.h"

/**
 * 
 */
UCLASS()
class GTABASE_API USimpleRandomMovementTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()

public:
	virtual void BuildTemplate(struct FMassEntityTemplateBuildContext& BuildContext, const class UWorld& World) const override;
};

USTRUCT()
struct FSimpleMovementFragment : public FMassFragment
{
	GENERATED_BODY()
	
	FVector Target;
};