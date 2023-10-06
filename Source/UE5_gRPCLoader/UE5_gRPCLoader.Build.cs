// Copyright Epic Games, Inc. All Rights Reserved.
using UnrealBuildTool;
using System;
using System.IO;

public class UE5_gRPCLoader : ModuleRules
{
	public UE5_gRPCLoader(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDefinitions.Add("PROTOBUF_ENABLE_DEBUG_LOGGING_MAY_LEAK_PII=0");
		PublicDefinitions.Add("PROTOBUF_BUILTIN_ATOMIC=0");
		PublicDefinitions.Add("__SIZEOF_INT128__=0");

		bEnableUndefinedIdentifierWarnings = false;

		string grpc_root = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../Binaries/ThirdParty/grpc/Win64"));
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string[] files = Directory.GetFiles(Path.GetFullPath(Path.Combine(grpc_root, "lib")), "*", SearchOption.AllDirectories);
			foreach (string file in files)
			{
				if (file.EndsWith(".lib")){
					Console.WriteLine(file);
					PublicAdditionalLibraries.Add(file);
				}
			}
			// inclyde zlib
			Console.WriteLine(Path.GetFullPath(Path.Combine(grpc_root, "bin", "zlib.dll")));
			PublicDelayLoadDLLs.Add(Path.GetFullPath(Path.Combine(grpc_root, "bin", "zlib.dll")));
			PublicIncludePaths.Add("$(PluginDir)/Binaries/ThirdParty/grpc/Win64/include");
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
		{
		}
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Projects"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
