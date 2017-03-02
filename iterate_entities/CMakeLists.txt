cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("Iterate_Entities")

#message("Supported features = ${CMAKE_CXX_COMPILE_FEATURES}")

message("\nUsing SketchUp SDK $ENV{SKETCHUP_SDK}\n")

find_path(SKETCHUP_INCLUDE_DIR SketchUpAPI/sketchup.h $ENV{SKETCHUP_SDK}/headers)
find_library(SKETCHUP_LIBRARY sketchupapi.lib $ENV{SKETCHUP_SDK}/binaries/sketchup/x64)
find_file(SKETCHUP_DLL SketchUpAPI.dll $ENV{SKETCHUP_SDK}/binaries/sketchup/x64)

file(GLOB SRC src/*.cpp src/*.h)
add_executable(main ${SRC})

# set VS Starup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)

include_directories(${SKETCHUP_INCLUDE_DIR})
target_link_libraries(main ${SKETCHUP_LIBRARY})

add_custom_command(
   TARGET main POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy
   ${SKETCHUP_DLL} $<TARGET_FILE_DIR:main>)
