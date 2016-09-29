cmake_minimum_required(VERSION 3.0)
project(gfftools CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(PROJ_INC_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJ_SRC_DIR ${PROJECT_SOURCE_DIR}/src)


include_directories(gclib)
add_subdirectory(gclib)
add_subdirectory(src)