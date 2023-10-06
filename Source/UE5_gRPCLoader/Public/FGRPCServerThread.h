#pragma once
#pragma warning(disable:4800)
#pragma warning(disable:4067)
#undef verify(expr)

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