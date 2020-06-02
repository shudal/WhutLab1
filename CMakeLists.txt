cmake_minimum_required(VERSION 3.10)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS -pthread)

add_executable(untitled2 main.cpp MyGraph.cpp MyGraph.h)