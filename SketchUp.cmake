IF(DEFINED ENV{SKETCHUP_SDK})
	message("\nUsing SketchUp SDK: $ENV{SKETCHUP_SDK}\n")
ELSE()
	message("SKETCHUP_SDK is not defined.\nYou must tell cmake where to find the SketchUp SDK.\n")
	return()
ENDIF()

find_path(SKETCHUP_INCLUDE_DIR SketchUpAPI/sketchup.h $ENV{SKETCHUP_SDK}/headers)
message("SKETCHUP_INCLUDE_DIR: ${SKETCHUP_INCLUDE_DIR}")

find_library(SKETCHUP_LIBRARY sketchupapi.lib $ENV{SKETCHUP_SDK}/binaries/sketchup/x64)
message("SKETCHUP_LIBRARY:     ${SKETCHUP_LIBRARY}")

find_file(SKETCHUP_DLL SketchUpAPI.dll $ENV{SKETCHUP_SDK}/binaries/sketchup/x64)
message("SKETCHUP_DLL          ${SKETCHUP_DLL}")

