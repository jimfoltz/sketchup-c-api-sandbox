@echo off
@echo Select:

echo   1. Visual Studio win64
echo   2. Visual Studio win32
echo   3. MinGW Makefiles

set /p generator=

if %generator%==1 (
	rd /q /s build-win64
	md build-win64
	cd build-win64
	cmake -G "Visual Studio 14 2015 Win64" ..
) else if %generator%==2 (
	rd /q /s build-win32
	md build-win32
	cd build-win32
	cmake -G "Visual Studio 14 2015" ..
) else if %generator%==3 (
	rd /q /s build-mingw
	md build-Mingw
	cd build-Mingw
	cmake -G "MinGW Makefiles" ..
)



