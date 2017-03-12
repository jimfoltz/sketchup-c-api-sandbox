cmake_minimum_required(VERSION 3.3)

project(assimp-to-skp)

math(EXPR BITS "${CMAKE_SIZEOF_VOID_P} * 8")
message(STATUS "BITS: " ${BITS})

include(../cmake/SketchUp.cmake)

INCLUDE(../cmake/assimp.cmake)

add_executable(a2s src/a2s.cpp)

target_include_directories(a2s PUBLIC ${SKETCHUP_INCLUDE_DIR})
target_include_directories(a2s PUBLIC ${ASSIMP_INCLUDE_DIR})

target_link_libraries(a2s PUBLIC ${ASSIMP_LIBRARY})
target_link_libraries(a2s PUBLIC ${SKETCHUP_LIBRARY})

if(MSVC)
add_custom_command(TARGET a2s POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SKETCHUP_DLL} $<TARGET_FILE_DIR:a2s>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ASSIMP_DLL} $<TARGET_FILE_DIR:a2s>
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT a2s)
endif()
