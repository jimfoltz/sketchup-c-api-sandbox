#cmake_minimum_required(VERSION 3.6)
#
project(wrapper)
#
#include(../cmake/SketchUp.cmake)
#include_directories(${SKETCHUP_INCLUDE_DIR})
#
file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS src/*.h)
#
#source_group("Source Files" FILES ${SOURCES})
#source_group("Header Files" FILES ${HEADERS})
#
#include_directories(src)
#
add_library(${PROJECT_NAME}  ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SKETCHUP_LIBRARY})
#target_include_directories(${PROJECT_NAME} PUBLIC ${SKETCHUP_INCLUDES})
#
#IF(MSVC)
#	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
#	# dll with export lib
#	set_property(TARGET ${PROJECT_NAME} PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
#ENDIF()
