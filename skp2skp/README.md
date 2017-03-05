# skp2skp

A command line app to convert between SketchUp file versions.  It was written
as a demo/example to learn the SketchUp API.

`s2s` can convert between SketchUp model versions from 3 to 2016.  All
supported versions include 3, 4, 5, 6, 7, 8, 2013, 2014, 2015, 2016

## Usage:

Convert `infile.skp` to a 2013 SketchUp file named `outfile.skp`

    > s2s -v 2013 infile.skp outfile.skp

## Build (Windows)

See the `build.cmd` script.

Dependencies:
*  the [tclap](http://tclap.sourceforge.net/) options parser header library.
* `SketchUpAPI.dll` from the SketchUp 2016 SDK.
* gcc compiler and toolchain. 
  I am using the [tdm-gcc](http://tdm-gcc.tdragon.net/) compiler suite.


Just run the `build.cmd` script.
```
    > build.cmd
    Build success.
    Done
```
----

```
USAGE:

   s2s  -v <string> [--] <input file> <output file>

Where:

   -v <string>,  --version <string>
     (required)  SketchUp version

   --,  --ignore_rest
     Ignores the rest of the labeled arguments following this flag.

   <input file>
     (required)  input file name

   <output file>
     (required)  output file name


   Supported vesions: 3, 4, 5, 6, 7, 8, 2013, 2014, 2015, 2106

```
