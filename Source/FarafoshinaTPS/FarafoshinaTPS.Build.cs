// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FarafoshinaTPS : ModuleRules
{
	public FarafoshinaTPS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"FarafoshinaTPS",
			"FarafoshinaTPS/Variant_Platforming",
			"FarafoshinaTPS/Variant_Platforming/Animation",
			"FarafoshinaTPS/Variant_Combat",
			"FarafoshinaTPS/Variant_Combat/AI",
			"FarafoshinaTPS/Variant_Combat/Animation",
			"FarafoshinaTPS/Variant_Combat/Gameplay",
			"FarafoshinaTPS/Variant_Combat/Interfaces",
			"FarafoshinaTPS/Variant_Combat/UI",
			"FarafoshinaTPS/Variant_SideScrolling",
			"FarafoshinaTPS/Variant_SideScrolling/AI",
			"FarafoshinaTPS/Variant_SideScrolling/Gameplay",
			"FarafoshinaTPS/Variant_SideScrolling/Interfaces",
			"FarafoshinaTPS/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
