cmake_minimum_required(VERSION 3.27)
project(assignment5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment5
        main.cpp
        UniqueWords.cpp
        UniqueWords.h
        Student.cpp
        Student.h
        Course.cpp
        Course.h)
