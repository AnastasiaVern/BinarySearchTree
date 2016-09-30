# CMakeLists.txt
cmake_minimum_required(VERSION 2.8.7)
project(BinarySearchTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(TESTS_SOURCE tests/main.cpp tests/find.cpp tests/size.cpp tests/catch.hpp)
set(SOURCE_FILES sources/BinarySearchTree.cpp include/BinarySearchTree.h examples/main.cpp)
add_executable(BinarySearchTree ${SOURCE_FILES}  )
add_executable(Tests ${TESTS_SOURCE} tests/main.cpp)
