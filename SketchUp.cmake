#MESSAGE(STATUS "\n\nINCLUDING SketchUp.cmake from ${CMAKE_CURRENT_SOURCE_DIR}")

#project(sketchup_sandbox)

IF(DEFINED ENV{SKETCHUP_SDK})
	message(STATUS "Using SketchUp SDK: $ENV{SKETCHUP_SDK}")
ELSE()
	message(STATUS "SKETCHUP_SDK is not defined.\nYou must tell cmake where to find the SketchUp SDK.")
	return()
ENDIF()

# SketchUp
find_path(SKETCHUP_SDK_ROOT NAMES version.txt PATHS ENV SKETCHUP_SDK)
message(STATUS "SKETCHUP_SDK_ROOT: ${SKETCHUP_SDK_ROOT}")

find_path(SKETCHUP_INCLUDES SketchUpAPI/sketchup.h ${SKETCHUP_SDK_ROOT}/headers)
message(STATUS "SKETCHUP_INCLUDES: ${SKETCHUP_INCLUDES}")

find_library(SKETCHUP_LIBRARY SketchUpAPI "${SKETCHUP_SDK_ROOT}/binaries/sketchup/x64")
message(STATUS "SKETCHUP_LIBRARY: " ${SKETCHUP_LIBRARY})

#include_directories(${SKETCHUP_INCLUDE_DIR})
file(GLOB SKETCHUP_DLLS ${SKETCHUP_SDK_ROOT}/binaries/sketchup/x64/*.dll)
#message(${SKETCHUP_DLLS})
