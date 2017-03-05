cmake_minimum_required(VERSION 3.7)

project("Iterate_Entities")

include(../SketchUp.cmake)

file(GLOB SRC src/*.cpp src/*.h)
add_executable(main ${SRC})
include_directories(${SKETCHUP_INCLUDE_DIR})
target_link_libraries(main ${SKETCHUP_LIBRARY})

# set VS Starup project
if(MSVC)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)

add_custom_command(
   TARGET main POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy
   ${SKETCHUP_DLL} $<TARGET_FILE_DIR:main>)

endif(MSVC)
