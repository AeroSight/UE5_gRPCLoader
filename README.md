UE5 Plugin UE5_gRPCLoader
===

Tested Platform
---
1. Windows 10 + UE5.2.1

**For now, the scripts (build.cmd & protoc.cmd) only support windows system**

Introduction for Windows users
---

This plugin is created for easily integrating `gRPC` framework in the UE5 project.

Step 1 Preparation
----

1. To install `Visual Stuidio`, `Git` and `CMake`, please refer to this [site](https://github.com/grpc/grpc/blob/master/BUILDING.md#windows). 



Step 2 Download the required command line tools 
---

1. Create the UE5 project as you planned. 
2. Download the zip file using the 
3. Go to the Windows system deskop and use keyshort `command + R` to open the `Run` windows. Inside the blank input bar in the `Run` window, type in `cmd` and clikc `Enter` key to launch the command line.
4. Use `cd` command to get into the directory where your project locates. Then use command `cd Plugins` to get into the Plugins directory.
5. Use command `git clone git@github.com:AeroSight/UE5_gRPCLoader.git` to download the plugin.

Step 3 Compile
---

1. Still in the command line, use command `cd UE5_gRPCLoader` to get into the plugin directory.
2. Type command `build.cmd` to execute the build script, then all you have to do is just wait for half an hour.
3. After the script finishes, you should be able to see the grpc library inside the directory `Binaries/ThirdParty`.

Step 4 Build protobuf message
---
1. Still in the command line, use command `protoc.cmd` to get the generated protobuf cpp files according to the predifined protobuf files.
2. Now you can see the generated protobuf files inside the directory `Source\UE5_gRPCLoader\Public\protos`.
3. Add these mcaros inside the file `Binaries\ThirdParty\grpc\Win64\include\google\protobuf\port_undef.inc` to avoid macro confilicts between gRPC and UE5.
    ```
    #pragma warning(disable:4800)
    #pragma warning(disable:4067)
    #undef verify(expr)
    ```

Now, you should be able to rebuild the whole UE5 project and the gRPC server will listen the port `30031`. You can modify the server settings in the file `Source\UE5_gRPCLoader\Private\FGRPCServerThread.cpp`.

You can include the header files provided by the plugin in the UE5 main game classes (Actor, GameMode...) using `#include UE5_gRPCLoader/Public/XXX.h"
