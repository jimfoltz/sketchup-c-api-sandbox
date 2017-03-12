MESSAGE(STATUS "\n\nINCLUDING SketchUp.cmake from ${CMAKE_CURRENT_SOURCE_DIR}")

IF(DEFINED ENV{SKETCHUP_SDK})
	message(STATUS "Using SketchUp SDK: $ENV{SKETCHUP_SDK}")
ELSE()
	message(STATUS "SKETCHUP_SDK is not defined.\nYou must tell cmake where to find the SketchUp SDK.")
	return()
ENDIF()

find_path(SKETCHUP_INCLUDE_DIR SketchUpAPI/sketchup.h $ENV{SKETCHUP_SDK}/headers)
message(STATUS "SKETCHUP_INCLUDE_DIR: ${SKETCHUP_INCLUDE_DIR}")

find_library(SKETCHUP_LIBRARY sketchupapi.lib $ENV{SKETCHUP_SDK}/binaries/sketchup/x64)
message(STATUS "SKETCHUP_LIBRARY:     ${SKETCHUP_LIBRARY}")

find_file(SKETCHUP_DLL SketchUpAPI.dll $ENV{SKETCHUP_SDK}/binaries/sketchup/x64)
message(STATUS "SKETCHUP_DLL          ${SKETCHUP_DLL}")

#include_directories(${SKETCHUP_INCLUDE_DIR})
