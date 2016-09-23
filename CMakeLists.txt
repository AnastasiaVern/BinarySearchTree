cmake_minimum_required(VERSION 2.8)
project(BinarySearchTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES examples/main.cpp include/BinarySearchTree.h sources/BinarySearchTree.cpp)
add_executable(untitled ${SOURCE_FILES})
