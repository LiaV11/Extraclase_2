cmake_minimum_required(VERSION 3.29)
project(Extraclase_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Extraclase_2
    graphing.cpp
    graphing.h
        linked_list.h
        linked_list.cpp)
