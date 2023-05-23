cmake_minimum_required(VERSION 3.5)

project(find_stone_pair)

set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(include)

set(SOURCE_FILE src/find_stone_pair.cpp)

add_library(find_stone_pair STATIC ${SOURCE_FILE})

add_subdirectory(third_party/googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB_RECURSE UT_SOURCE_FILE ut/*.cpp)
add_executable(test_find_stone_pair ${UT_SOURCE_FILE})
target_link_libraries(test_find_stone_pair ${PROJECT_NAME} gtest gtest_main)