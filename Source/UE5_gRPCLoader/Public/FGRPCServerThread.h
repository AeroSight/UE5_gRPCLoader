#pragma once
#include "CoreMinimal.h"
#include "HAL/Runnable.h"

class FGRPCServerThread final: public FRunnable {
public:
    FGRPCServerThread();

    virtual bool Init() override;
    virtual uint32 Run() override;
    virtual void Stop() override;
    virtual void Exit() override;
};