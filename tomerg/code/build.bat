@echo Build time
@echo off

rmdir ..\..\build /s /q
mkdir ..\..\build
pushd ..\..\build
cl -Zi ..\tomerg\code\win32_tomerg.cpp user32.lib Gdi32.lib
popd
