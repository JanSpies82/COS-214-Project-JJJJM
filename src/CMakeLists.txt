cmake_minimum_required(VERSION 2.6)
project (Project_JJJJM)

# Locate GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link all files in src directory
file(GLOB src
     "*.h"
     "*.cpp"
     "../test/*.cpp"
)

add_executable(main ${src})
target_link_libraries(main ${GTEST_LIBRARIES} pthread)