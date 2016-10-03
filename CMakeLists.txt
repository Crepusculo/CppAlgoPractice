cmake_minimum_required(VERSION 3.6)
project(AlgoPractice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DataStructure/LinkListSample.cpp DataStructure/LinkListSample.h test/test_build.h test/test_link_list_sample.h)
add_executable(AlgoPractice ${SOURCE_FILES})