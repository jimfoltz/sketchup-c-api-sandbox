cmake_minimum_required(VERSION 3.7)

include("../SketchUp.cmake")

file(GLOB SRCS src/*.cpp src/*.h)

add_executable(transform ${SRCS})
include_directories(${SKETCHUP_INCLUDE_DIR})
target_link_libraries(transform ${SKETCHUP_LIBRARY})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT transform)
#set_target_properties(transform PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_custom_command(
   TARGET transform POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy
   ${SKETCHUP_DLL} $<TARGET_FILE_DIR:transform>)
