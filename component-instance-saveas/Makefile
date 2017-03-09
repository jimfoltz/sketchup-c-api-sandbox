SDKVERSION = SDK_Win_16-1-1450
HEADERS = -I..\..\..\SDK\$(SDKVERSION)\headers
DLL = ..\..\..\SDK\$(SDKVERSION)\binaries\sketchup\x86\SketchUpAPI.dll

EXE = save_instance

CFLAGS = -Wall -m32 -static -static-libgcc -static-libstdc++

all:
	g++ $(CFLAGS) -o $(EXE) $(HEADERS) $(DLL) src/$(EXE).cpp
	xcopy $(DLL)

