# Comment

project(s2s)

cmake_minimum_required(VERSION 3.3)

math(EXPR BITS "${CMAKE_SIZEOF_VOID_P} * 8")
message("BITS: " ${BITS})

find_path(SKETCHUP_SDK version.txt ../../../SDK/SDK_Win_16-1-1450)
message("SKETCHUP_SDK: ${SKETCHUP_SDK}")

find_path(SKETCHUP_INCLUDE_DIR SketchUpAPI/sketchup.h ${SKETCHUP_SDK}/headers)
message("SKETCHUP_INCLUDE_DIR: ${SKETCHUP_INCLUDE_DIR}")

if( BITS EQUAL 64 )
	find_library(SKETCHUP_LIBRARY sketchupapi.lib ${SKETCHUP_SDK}/binaries/sketchup/x64)
	find_file(SKETCHUP_DLL SketchUpAPI.dll ${SKETCHUP_SDK}/binaries/sketchup/x64)
else()
	find_library(SKETCHUP_LIBRARY sketchupapi.lib ${SKETCHUP_SDK}/binaries/sketchup/x86)
	find_file(SKETCHUP_DLL SketchUpAPI.dll ${SKETCHUP_SDK}/binaries/sketchup/x86)
endif()
message("SKETCHUP_LIBRARY: ${SKETCHUP_LIBRARY}")
message("SKETCHUP_DLL: ${SKETCHUP_DLL}")


include_directories(${SKETCHUP_INCLUDE_DIR})

add_executable(s2s src/s2s.cpp)

target_link_libraries(s2s PUBLIC ${SKETCHUP_LIBRARY})


if(MSVC)
add_custom_command(TARGET s2s POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SKETCHUP_DLL} $<TARGET_FILE_DIR:s2s>
	#COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ASSIMP_DLL} $<TARGET_FILE_DIR:s2s>
	)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT s2s)

endif()
