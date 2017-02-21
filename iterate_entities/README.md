# iterate entities


## Build the Build

Requires cmake. I am working on Windows 10 64-bit, and Visual Studio 2015
Express for Desktop.

Set an ENV variable named `SKETCHUP_SDK` where you will find the `headers` and
`binary` folders of the SketchUp SDK. For me, this is currently:

    C:\Users\Jim\SketchUp\SDK\SDK_Win_x64_17.2.2555


    md build
    cd build
    cmake -G "Visual Studio 14 2015 Win64" ..

## Compile the build

    cmake --build build/ [--config Release|Debug]

## Run

    ./build/Debug/main.exe filename.skp


