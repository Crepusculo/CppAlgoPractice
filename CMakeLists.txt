cmake_minimum_required(VERSION 3.6)
project(AlgoPractice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp data_structure/LinkListSample.cpp data_structure/LinkListSample.h test/test_build.h test/test_link_list_sample.h data_structure/QueueArraySample.h test/test_queue_array_sample.h cpp_feature_toys/class_inherits/TangGefu.cpp cpp_feature_toys/class_inherits/TangGefu.h test/test_cft_class_inherits.h)
add_executable(AlgoPractice ${SOURCE_FILES})
add_executable(caesar_cipher algo/caesar_cipher.cpp)