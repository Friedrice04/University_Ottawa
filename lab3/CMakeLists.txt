cmake_minimum_required(VERSION 3.29)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

include_directories(Ex2)

add_executable(lab3
    Ex1/myFile1a.cpp
    Ex1/myFile1b.cpp
    Ex2/myLinkedList.cpp
    Ex2/myLinkedList.h)
