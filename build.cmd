@REM clone the gRPC repo from github
for /f "tokens=*" %%i in ('cd') do set PLUGIN_DIR_ROOT=%%i
cd %PLUGIN_DIR_ROOT%/Source/ThirdParty
git clone --recurse-submodules -b v1.59.x --depth 1 --shallow-submodules https://github.com/grpc/grpc
cd grpc
@REM git submodule update --init
md .build
cd .build
cmake -DgRPC_INSTALL=ON -DCMAKE_INSTALL_PREFIX=../../../../Binaries/ThirdParty/grpc/Win64 .. -G "Visual Studio 17 2022"
cmake --build . -j %NUMBER_OF_PROCESSORS%  --config Release
cmake --install .

@REM move the zlib.dll to the Plugin file to enable the UE5 find the dll.
cd %PLUGIN_DIR_ROOT%
cp Binaries/ThirdParty/grpc/Win64/bin/zlib.dll Binaries/Win64