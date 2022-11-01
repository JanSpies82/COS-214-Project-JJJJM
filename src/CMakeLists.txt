cmake_minimum_required(VERSION 3.16)
project (Project_JJJJM)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB src
     "*.h"
     "*.cpp"
)

add_executable(main ${src})
# set(CMAKE_BUILD_TYPE Debug)