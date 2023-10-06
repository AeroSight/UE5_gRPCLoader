@echo off
@REM compile the proto msg file
for /f "tokens=*" %%i in ('cd') do set PLUGIN_DIR_ROOT=%%i
cd %PLUGIN_DIR_ROOT%
set PROTOC=Binaries\ThirdParty\grpc\Win64\bin\protoc.exe
set SOURCE_DIR=Source
set PROTOC_SRC_DIR=Source\protos
set PROTOC_DES_DIR=Source\UE5_gRPCLoader\Public\protos
set PROTOC_C_PLUGIN=%PLUGIN_DIR_ROOT%\Binaries\ThirdParty\grpc\Win64\bin\grpc_cpp_plugin.exe

@REM compile the messages and services
rd %PROTOC_DES_DIR% /s /q 
mkdir %PROTOC_DES_DIR%

SETLOCAL DisableDelayedExpansion
SET r=%__CD__%
FOR /R %PROTOC_SRC_DIR% %%F IN (*) DO (
  SET abs_path=%%F
  SETLOCAL EnableDelayedExpansion
  %PROTOC% -I %SOURCE_DIR% --cpp_out=%PROTOC_DES_DIR% !abs_path:%r%=!
  %PROTOC% -I %SOURCE_DIR% --plugin=protoc-gen-grpc=%PROTOC_C_PLUGIN% --grpc_out=%PROTOC_DES_DIR% !abs_path:%r%=!
  ENDLOCAL
)
