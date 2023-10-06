// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_gRPCLoader.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"


#define LOCTEXT_NAMESPACE "FUE5_gRPCLoaderModule"

void FUE5_gRPCLoaderModule::StartupModule()
{
    const FString plugin_dir = IPluginManager::Get().FindPlugin("UE5_gRPCLoader")->GetBaseDir();

#if PLATFORM_WINDOWS
    FString dll_path = FPaths::Combine(*plugin_dir, TEXT("Binaries"), TEXT("ThirdParty"), TEXT("grpc"), TEXT("Win64"), TEXT("bin"));   
    FPlatformProcess::AddDllDirectory(*dll_path);
#endif
    FGRPCServerThread* runnable = new FGRPCServerThread();
    FRunnableThread *thread = FRunnableThread::Create(runnable, TEXT("gRPC-server"));
}

void FUE5_gRPCLoaderModule::ShutdownModule() {
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUE5_gRPCLoaderModule, UE5_gRPCLoader)
