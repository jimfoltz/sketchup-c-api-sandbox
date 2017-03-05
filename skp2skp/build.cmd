@echo off

g++ --help > NUL 2> NUL

if %errorlevel% equ 0 goto build
rem call c:\tdm-gcc-64\mingwvars.bat

:build
set SDKVERSION=SDK_Win_16-1-1450
set HEADERS=-I..\..\..\SDK\%SDKVERSION%\headers -IC:\Users\Jim\Code\tclap-1.2.1\include
set DLL=..\..\..\SDK\%SDKVERSION%\binaries\sketchup\x86\sketchupapi.dll

g++ -Wall --std=c++11 -m32 ^
  -static -static-libgcc -static-libstdc++ ^
  -o s2s.exe %HEADERS% %DLL% src/s2s.cpp

if %errorlevel% equ 0 goto copy_dll

echo Build failed.
goto fin

:copy_dll
echo Build success.
if not exist sketchupapi.dll copy %DLL% .

:fin
echo Done

