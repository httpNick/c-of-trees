cmake_minimum_required(VERSION 3.3)
project(c-of-trees)
add_subdirectory(bst)
add_subdirectory(red-black)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES)