# Comment

project(assimp-to-skp)

cmake_minimum_required(VERSION 3.3)

math(EXPR BITS "${CMAKE_SIZEOF_VOID_P} * 8")
message("BITS: " ${BITS})

message("\nUsing SketchUp SDK " $ENV{SKETCHUP_SDK})
find_path(SKETCHUP_INCLUDE_DIR SketchUpAPI/sketchup.h $ENV{SKETCHUP_SDK}/headers)
find_library(SKETCHUP_LIBRARY sketchupapi.lib $ENV{SKETCHUP_SDK}/binaries/sketchup/x64)
find_file(SKETCHUP_DLL SketchUpAPI.dll $ENV{SKETCHUP_SDK}/binaries/sketchup/x64)


set(ASSIMP_HEADER_DIR "../../assimp/include")
set(ASSIMP_LIB_DIR "../../assimp/build${BITS}/code/Release")
set(ASSIMP_DLL "${ASSIMP_LIB_DIR}/assimp-vc140-mt.dll")


include_directories(${SKETCHUP_INCLUDE_DIR})
include_directories(${ASSIMP_HEADER_DIR})

find_library(SK sketchupapi "${SKETCHUP_LIB_DIR}")
find_library(AI assimp-vc140-mt "${ASSIMP_LIB_DIR}")

add_executable(a2s src/a2s.cpp)

target_link_libraries(a2s PUBLIC ${AI})
target_link_libraries(a2s PUBLIC ${SK})

add_custom_command(TARGET a2s POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SKETCHUP_DLL} $<TARGET_FILE_DIR:a2s>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ASSIMP_DLL} $<TARGET_FILE_DIR:a2s>
)

