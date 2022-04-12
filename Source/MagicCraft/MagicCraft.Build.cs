// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MagicCraft : ModuleRules
{
	public MagicCraft(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
