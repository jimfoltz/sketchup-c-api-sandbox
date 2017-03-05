# assimp-to-skp

Command-line app to convert several 3D model formats to .skp

## Build the Build

Requires cmake. I am working on Windows 10 64-bit, and Visual Studio 2015
Express for Desktop.

Set an ENV variable named `SKETCHUP_SDK` where you will find the `headers` and
`binary` folders of the SketchUp SDK. For me, this is currently:

    > set SKETCHUP_SDK="C:/Users/Jim/SketchUp/SDK/SDK_Win_x64_17.2.2555"


    md build
    cd build
    cmake -G "Visual Studio 14 2015 Win64" ..

## Compile the build

    cmake --build build/ [--config Release|Debug]

## Run

    ./build/Debug/a2s.exe filename.[stl|ply]


## List of all assimp supported import file types



`*.3d;*.3ds;*.ac;*.ac3d;*.acc;*.ase;*.ask;*.assbin;*.b3d;*.blend;*.bvh;*.cob;*.csm;*.dae;*.dxf;*.enff;*.fbx;*.glb;*.gltf;*.hmp;*.ifc;*.ifczip;*.irr;*.irrmesh;*.lwo;*.lws;*.lxo;*.md2;*.md3;*.md5anim;*.md5camera;*.md5mesh;*.mdc;*.mdl;*.mesh;*.mesh.xml;*.mot;*.ms3d;*.ndo;*.nff;*.obj;*.off;*.ogex;*.pk3;*.ply;*.prj;*.q3o;*.q3s;*.raw;*.scn;*.smd;*.stl;*.ter;*.uc;*.vta;*.x;*.xgl;*.xml;*.zgl
`