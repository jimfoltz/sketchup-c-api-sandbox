cmake_minimum_required(VERSION 3.7)

project(sketchup_wrapper)

message("\nUsing SketchUp SDK  $ENV{SKETCHUP_SDK}\n")
find_path(SKETCHUP_INCLUDE_DIR SketchUpAPI/sketchup.h $ENV{SKETCHUP_SDK}/headers)
find_library(SKETCHUP_LIBRARY sketchupapi.lib $ENV{SKETCHUP_SDK}/binaries/sketchup/x64)
find_file(SKETCHUP_DLL SketchUpAPI.dll $ENV{SKETCHUP_SDK}/binaries/sketchup/x64)


file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS src/*.h)

source_group("Source Files" FILES ${SOURCES})
source_group("Header Files" FILES ${HEADERS})

include_directories(src)
include_directories($ENV{SKETCHUP_INCLUDE_DIR})

add_library(${PROJECT_NAME}  ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SKETCHUP_LIBRARY})
