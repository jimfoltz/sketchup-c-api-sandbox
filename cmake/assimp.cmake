find_path(ASSIMP_INCLUDE_DIR NAMES assimp/anim.h HINTS ${ASSIMP_ROOT_DIR}/include ../../assimp/include)
message("ASSIMP_INCLUDE_DIR: ${ASSIMP_INCLUDE_DIR}")

find_path(ASSIMP_LIB_DIR assimp-vc140-mt.lib ../../builds/assimp-win${BITS}/code/Release)
message("ASSIMP_LIB_DIR: ${ASSIMP_LIB_DIR}")

find_library(ASSIMP_LIBRARY assimp-vc140-mt.lib "${ASSIMP_LIB_DIR}")
message("ASSIMP_LIB:     ${ASSIMP_LIBRARY}")

find_file(ASSIMP_DLL assimp-vc140-mt.dll  "${ASSIMP_LIB_DIR}" NO_DEFAULT_PATH NO_CMAKE_ENVIRONMENT_PATH NO_SYSTEM_ENVIRONMENT_PATH)
message("ASSIMP_DLL:     ${ASSIMP_DLL}")

#include_directories(${ASSIMP_INCLUDE_DIR})
