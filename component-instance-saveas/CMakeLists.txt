cmake_minimum_required(VERSION 3.7)

project("Save_Instances")

include(../SketchUp.cmake)

set(t save_instances)

file(GLOB SRC src/*.cpp src/*.h)

add_executable(${t} ${SRC})

#add_subdirectory(../c++-wrapper)

#file(GLOB WRAPPER_INCLUDES ../c++-wrapper/src/*.h)
include_directories(${SKETCHUP_INCLUDE_DIR})
include_directories(../c++-wrapper/src)

target_link_libraries(${t} ${SKETCHUP_LIBRARY})
target_link_libraries(${t} optimized ../../c++-wrapper/build-win64/Release/su_wrapper)
target_link_libraries(${t} debug  ../../c++-wrapper/build-win64/Debug/su_wrapper)
target_link_libraries(${t} ../../c++-wrapper/build-win64/Release/su_wrapper)

# set VS Starup project
if(MSVC)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${t})

add_custom_command(
   TARGET ${t} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy
   ${SKETCHUP_DLL} $<TARGET_FILE_DIR:${t}>)

endif(MSVC)
