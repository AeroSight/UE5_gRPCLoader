#include "FGRPCServerThread.h"
#include "grpcpp/server_builder.h"
#include "grpcpp/server_context.h"
#include "grpcpp/server.h"
#include "grpcpp/security/server_credentials.h"
#include "protos/HelloWorld.grpc.pb.h"
#include "Windows/AllowWindowsPlatformAtomics.h"
#include "Windows/HideWindowsPlatformAtomics.h"


FGRPCServerThread::FGRPCServerThread() {

}

bool FGRPCServerThread::Init() {
    return true;
}

uint32 FGRPCServerThread::Run() {
    std::string server_addr("0.0.0.0:30031");
    grpc::ServerBuilder server;
    server.AddListeningPort(server_addr, grpc::InsecureServerCredentials());

    HelloWorld::Service service;
    server.RegisterService(&service);
    std::unique_ptr<grpc::Server> grpc_servre(server.BuildAndStart());
    grpc_servre->Wait();
    return 0;
}


void FGRPCServerThread::Stop() {

}

void FGRPCServerThread::Exit() {

}