// Fill out your copyright notice in the Description page of Project Settings.


#include "Yohan/SimpleRandomMovementTrait.h"
#include "MassEntityTemplateRegistry.h"

void USimpleRandomMovementTrait::BuildTemplate(struct FMassEntityTemplateBuildContext& BuildContext, const class UWorld& World) const {
	
	BuildContext.AddFragment<FSimpleMovementFragment>();
}