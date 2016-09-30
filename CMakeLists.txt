# CMakeLists.txt
cmake_minimum_required(VERSION 2.8.7)
project(BinarySearchTree)

include_directories(include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(TESTS_SOURCES tests/main.cpp tests/find.cpp tests/size.cpp tests/insert.cpp)

add_executable(Tests ${TESTS_SOURCES} tests/main.cpp)
