# skp2skp

A command line app to convert between SketchUp file versions.  It was written
as a demo/example to learn the SketchUp API.

`s2s` can convert between SketchUp model versions from 3 to 2016.  The full list of versions include: 3, 4, 5, 6, 7, 8, 2013, 2014, 2015, 2016

## Usage:

To convert `infile.skp` to a 2013 SketchUp file named `outfile.skp`:

    > s2s 2013 infile.skp outfile.skp

Looping over all files can be done using the user's shell or command syntax and specifying a sub-folder prefix to the output file:

    # psuedo-code
    mkdir tmp
    for each skp in *.skp
      s2s 2013 skp tmp/skp
    end

## Build (Windows)

See the `build.cmd` script, or the `Makefile`.

Dependencies:
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
