cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 14)

project("sketchup_sandbox")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(SketchUp.cmake)

include_directories("." ${SKETCHUP_INCLUDES} "utilites")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/_bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/_bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/_bin")

IF(MSVC)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/_bin )
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/_bin )
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/_bin )
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/_bin )
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/_bin )
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/_bin )
ENDIF()

add_subdirectory(wrapper)
add_subdirectory(100_Reading)
add_subdirectory(101_Writing)
#add_subdirectory(assimp-to-skp)
#add_subdirectory(skp2skp)
add_subdirectory(iterate_entities)
add_subdirectory(transform_entities)
add_subdirectory(save_instances)
add_subdirectory(typed-value-array-example)


