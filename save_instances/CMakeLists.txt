#cmake_minimum_required(VERSION 3.6)
#
project(save_instances)
#
#include(../cmake/SketchUp.cmake)
#
file(GLOB SRC src/*.cpp src/*.h)
add_executable(${PROJECT_NAME} ${SRC})
#include_directories(${SKETCHUP_INCLUDE_DIR})
#include_directories(../wrapper/src)
target_link_libraries(${PROJECT_NAME} ${SKETCHUP_LIBRARY})
target_link_libraries(${PROJECT_NAME} wrapper)
#
## set VS Starup project
#if(MSVC)
#
#	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
#
#	add_custom_command(
#		TARGET ${PROJECT_NAME} POST_BUILD
#		COMMAND ${CMAKE_COMMAND} -E copy ${SKETCHUP_DLL} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
#
#endif(MSVC)
