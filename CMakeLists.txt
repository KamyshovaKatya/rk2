cmake_minimum_required(VERSION 3.10)
project(rk2)

set(CMAKE_CXX_STANDARD 11)

# Указываем путь к исходным файлам
add_executable(rk2 main.cpp)

# Добавляем Google Test
add_subdirectory(googletest)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Добавляем тесты
add_executable(runTests tests/test_main.cpp)

target_link_libraries(runTests gtest gtest_main)
add_test(NAME runTests COMMAND runTests)

