@echo Build time
@echo off

mkdir ..\..\build
pushd ..\..\build
cl -Zi ..\tomerg\code\win32_tomerg.cpp user32.lib
popd
