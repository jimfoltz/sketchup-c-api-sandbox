cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include("../SketchUp.cmake")

file(GLOB SRCS src/*.cpp src/*.h)

add_executable(transform ${SRCS})
include_directories(${SKETCHUP_INCLUDE_DIR})
target_link_libraries(transform ${SKETCHUP_LIBRARY})

if(MSVC)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT transform)

add_custom_command(
   TARGET transform POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy
   ${SKETCHUP_DLL} $<TARGET_FILE_DIR:transform>)

endif()
