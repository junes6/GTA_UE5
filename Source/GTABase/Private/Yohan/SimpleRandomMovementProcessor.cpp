// Fill out your copyright notice in the Description page of Project Settings.


#include "Yohan/SimpleRandomMovementProcessor.h"
#include "Yohan/SimpleRandomMovementTrait.h"
#include "MassEntitySubsystem.h"
#include "MassEntityQuery.h"
#include "MassCommonFragments.h"
#include "MassEntityTemplateRegistry.h"

USimpleRandomMovementProcessor::USimpleRandomMovementProcessor()
{
	bAutoRegisterWithProcessingPhases = true;
	ExecutionFlags = (int32)EProcessorExecutionFlags::All;
	ExecutionOrder.ExecuteBefore.Add(UE::Mass::ProcessorGroupNames::Avoidance);
}

void USimpleRandomMovementProcessor::ConfigureQueries()
{
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadWrite);
	// EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadWrite, EMassFragmentPresence::Any);
	EntityQuery.AddRequirement<FSimpleMovementFragment>(EMassFragmentAccess::ReadWrite);
	// EntityQuery.AddRequirement<FSimpleMovementFragment>(EMassFragmentAccess::ReadWrite, EMassFragmentPresence::Any);

	EntityQuery.RegisterWithProcessor(*this);
}

void USimpleRandomMovementProcessor::Execute(struct FMassEntityManager& EntityManager, struct FMassExecutionContext& Context)
{
	// Context.SetExecutionType(EMassExecutionContextType::Processor);
	EntityQuery.ForEachEntityChunk(EntityManager, Context, ([this](FMassExecutionContext& Context)
		{
			const TArrayView<FTransformFragment> TransformsList = Context.GetMutableFragmentView<FTransformFragment>();
			const TArrayView<FSimpleMovementFragment> SimpleMovementsList = Context.GetMutableFragmentView<FSimpleMovementFragment>();
			const float WorldDeltaTime = Context.GetDeltaTimeSeconds();

			int32 NumEntities = Context.GetNumEntities();

			for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); ++EntityIndex)
			{
				FTransform& Transform = TransformsList[EntityIndex].GetMutableTransform();
				FVector& MoveTarget = SimpleMovementsList[EntityIndex].Target;

				FVector CurrentLocation = Transform.GetLocation();
				FVector TargetVector = MoveTarget - CurrentLocation;

				if (TargetVector.Size() <= 20.f)
				{
					MoveTarget = FVector(FMath::FRandRange(-1.f, 1.f) * 1000.f, FMath::RandRange(-1.f, 1.f) * 1000.f, CurrentLocation.Z);
				}
				else
				{
					Transform.SetLocation(CurrentLocation + TargetVector.GetSafeNormal() * 400.f * WorldDeltaTime);
				}
			}
		}));
}