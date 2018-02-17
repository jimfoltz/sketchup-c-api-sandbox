cmake_minimum_required(VERSION 3.9)

#set(CMAKE_GENERATOR "Visual Studio 15 2017 Win64")
set(CMAKE_CXX_STANDARD 14)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project("TypedValueTest")

# SketchUp
find_path(SKETCHUP_SDK_ROOT NAMES version.txt PATHS ENV SKETCHUP_SDK)
find_path(SKETCHUP_HEADERS SketchUpAPI/sketchup.h ${SKETCHUP_SDK_ROOT}/headers)
find_library(SKETCHUP_LIBRARY SketchUpAPI ${SKETCHUP_SDK_ROOT}/binaries/sketchup/x64)

include_directories("${SKETCHUP_HEADERS}")

set(exe_name main)

add_executable(${exe_name} src/main.cpp )

target_link_libraries(${exe_name} ${SKETCHUP_LIBRARY})

if(MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${exe_name})
endif()

#install(TARGETS main DESTINATION "C:/Users/Jim/bin/main")

add_custom_command(TARGET ${exe_name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
		"${SKETCHUP_SDK_ROOT}/binaries/sketchup/x64/SketchUpAPI.dll"
		"${SKETCHUP_SDK_ROOT}/binaries/sketchup/x64/SketchUpCommonPreferences.dll"
        $<TARGET_FILE_DIR:main>
)
