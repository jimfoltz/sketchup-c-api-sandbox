cmake_minimum_required(VERSION 3.7)

project(su_wrapper)

include(../SketchUp.cmake)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS src/*.h)

source_group("Source Files" FILES ${SOURCES})
source_group("Header Files" FILES ${HEADERS})

include_directories(src)
include_directories(${SKETCHUP_INCLUDE_DIR})

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SKETCHUP_LIBRARY})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT su_wrapper)

# dll with export lib
set_property(TARGET su_wrapper PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
