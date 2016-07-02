@echo Build time
@echo off

mkdir ..\..\build
pushd ..\..\build
cl ..\tomerg\code\win32_tomerg.cpp
popd
