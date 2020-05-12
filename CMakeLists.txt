cmake_minimum_required(VERSION 3.10)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS -pthread)


add_subdirectory(googletest)
include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)
add_executable(untitled1 main.cpp src/piczip/PhotoCompressionByHuffman.h src/piczip/PhotoCompressionByHuffman.cpp src/piczip/main.cpp src/piczip/Huffman.cpp src/piczip/Huffman.h src/test/piczip/piczip_test.cpp)

target_link_libraries(untitled1 gtest gtest_main)
target_link_libraries(untitled1 gmock gmock_main)