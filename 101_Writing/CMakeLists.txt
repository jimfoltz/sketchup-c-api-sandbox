PROJECT(101_Writing)
#
#INCLUDE(../cmake/SketchUp.cmake)
#
FILE(GLOB SRC src/*.cpp)
#
add_executable(${PROJECT_NAME} ${SRC})
#
#include_directories(${SKETCHUP_INCLUDE_DIR})
#
target_link_libraries(${PROJECT_NAME} ${SKETCHUP_LIBRARY})
#
#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SKETCHUP_DLL} $<TARGET_FILE_DIR:${PROJECT_NAME}>
#)
