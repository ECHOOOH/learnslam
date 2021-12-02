
# cliam the lowest version
cmake_minimum_required(VERSION 2.8)

# cliam a project
project (useHello)
set(SRC_LIST ${PROJECT_SOURCE_DIR}/src/useHello.cpp)
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
include_directories(${PROJECT_SOURCE_DIR}/helloSlam/inc)
find_library(HELLOSLAM_LIB libhello.a ${PROJECT_SOURCE_DIR}/helloSlam/lib)

add_executable(useHello ${SRC_LIST})
target_link_libraries(useHello ${HELLOSLAM_LIB})


