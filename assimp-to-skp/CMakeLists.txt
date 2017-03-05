cmake_minimum_required(VERSION 3.3)

project(assimp-to-skp)

math(EXPR BITS "${CMAKE_SIZEOF_VOID_P} * 8")
message("BITS: " ${BITS})

find_path(ASSIMP_INCLUDE_DIR NAMES assimp/anim.h HINTS ${ASSIMP_ROOT_DIR}/include ../../assimp/include)
message("ASSIMP_INCLUDE_DIR: ${ASSIMP_INCLUDE_DIR}")

find_path(ASSIMP_LIB_DIR NAMES assimp-vc140-mt.lib HINTS ../../assimp/build-win${BITS}/code/Release)
message("ASSIMP_LIB_DIR: ${ASSIMP_LIB_DIR}")

set(ASSIMP_DLL "${ASSIMP_LIB_DIR}/assimp-vc140-mt.dll")
message("ASSIMP_DLL: ${ASSIMP_DLL}")
find_library(ASSIMP_LIB assimp-vc140-mt "${ASSIMP_LIB_DIR}")
message("ASSIMP_LIB: ${ASSIMP_LIB}")

include(../SketchUp.cmake)

include_directories(${SKETCHUP_INCLUDE_DIR})
include_directories(${ASSIMP_INCLUDE_DIR})


add_executable(a2s src/a2s.cpp)

target_link_libraries(a2s PUBLIC ${ASSIMP_LIB})
target_link_libraries(a2s PUBLIC ${SKETCHUP_LIBRARY})


if(MSVC)
add_custom_command(TARGET a2s POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SKETCHUP_DLL} $<TARGET_FILE_DIR:a2s>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ASSIMP_DLL} $<TARGET_FILE_DIR:a2s>
	)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT a2s)

endif()
