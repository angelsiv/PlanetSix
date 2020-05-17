// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PlanetSix : ModuleRules
{
	public PlanetSix(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Slate", "SlateCore", "Engine", "InputCore","UMG","AIModule" });
        DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
    }
}
