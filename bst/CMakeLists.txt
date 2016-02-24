cmake_minimum_required(VERSION 3.3)
project(bst)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES tree.c main.c)
add_executable(bst ${SOURCE_FILES} main.c)