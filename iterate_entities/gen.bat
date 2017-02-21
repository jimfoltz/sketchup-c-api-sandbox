@echo off

echo 1. Win64
echo 2. Win32
echo 3. MinGW

set /p generator=

if %generator%==1 (
	rd /q /s build-Win64
	md build-Win64
	cd build-Win64
	cmake -G "Visual Studio 14 2015 Win64" ..
) else if %generator%==2 (
	rd /q /s build-Win32
	md build-Win32
	cd build-Win32
	cmake -G "Visual Studio 14 2015" ..
) else if %generator%==3 (
	rd /q /s build-MinGW
	md build-MinGW
	cd build-MinGW
	cmake -G "MinGW Makefiles" ..
)



