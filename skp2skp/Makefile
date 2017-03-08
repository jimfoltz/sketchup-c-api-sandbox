SDKVERSION = SDK_Win_16-1-1450
HEADERS = -I..\..\..\SDK\$(SDKVERSION)\headers
DLL = ..\..\..\SDK\$(SDKVERSION)\binaries\sketchup\x86\sketchupapi.dll

CFLAGS = -Wall -m32 -static -static-libgcc -static-libstdc++

all:
	g++ $(CFLAGS) -o s2s $(HEADERS) $(DLL) src/s2s.cpp

clean:
	del s2s.exe

