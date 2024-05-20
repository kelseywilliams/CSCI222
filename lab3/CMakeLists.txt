cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp Matrix.cpp Matrix.h
        read_input.cpp
        read_input.h)
