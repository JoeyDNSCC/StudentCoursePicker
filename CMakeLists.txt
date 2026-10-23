cmake_minimum_required(VERSION 4.3)
project(courses)

set(CMAKE_CXX_STANDARD 20)

add_executable(courses main.cpp
        Student.cpp
        Student.h)
