// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GTABase : ModuleRules
{
	public GTABase(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "UMG", "MassCommon", "MassEntity", "MassCrowd" });

		// AI dependencies
		PrivateDependencyModuleNames.AddRange(new string[] { "AIModule", "NavigationSystem" });

		// Gameplay Ability System dependencies
		PublicDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks" });

		// Uncomment, if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
	}
}
