cmake_minimum_required(VERSION 3.10)
project(rk2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rk2 ./main.cpp)

option(BUILD_TESTS "Build tests" OFF)

add_library(src STATIC ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB SRC_TEST_SOURCES tests/*.cpp)
  add_executable(check ${SRC_TEST_SOURCES}) 
  target_link_libraries(check src gtest_main)
  add_test(NAME check COMMAND check)
endif()



#include(CPack.cmake)

