// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ReservedForces : ModuleRules
{
	public ReservedForces(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
