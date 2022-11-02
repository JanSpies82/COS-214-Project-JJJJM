cmake_minimum_required(VERSION 3.10)
project (Project_JJJJM)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB test
     "../src/*.h"
     "../src/*.cpp"
     "*.cpp"
)

list(FILTER test EXCLUDE REGEX ".*main\\.cpp$")
add_executable(test ${test})
target_link_libraries(test ${GTEST_LIBRARIES} pthread)
set(CMAKE_BUILD_TYPE Debug)