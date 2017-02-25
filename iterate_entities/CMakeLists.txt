cmake_minimum_required(VERSION 3.7)

project("Iterate_Entities")

message("\nUsing SketchUp SDK " $ENV{SKETCHUP_SDK})

find_path(SKETCHUP_INCLUDE_DIR SketchUpAPI/sketchup.h $ENV{SKETCHUP_SDK}/headers)
find_library(SKETCHUP_LIBRARY sketchupapi.lib $ENV{SKETCHUP_SDK}/binaries/sketchup/x64)
find_file(SKETCHUP_DLL SketchUpAPI.dll $ENV{SKETCHUP_SDK}/binaries/sketchup/x64)

add_executable(main src/main.cpp src/type_name.h src/output_sketchup_error.h)

include_directories(${SKETCHUP_INCLUDE_DIR})
target_link_libraries(main ${SKETCHUP_LIBRARY})

add_custom_command(
   TARGET main POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy
   ${SKETCHUP_DLL} $<TARGET_FILE_DIR:main>)
