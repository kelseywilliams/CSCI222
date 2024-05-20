cmake_minimum_required(VERSION 3.27)
project(assignment7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment7
        main.cpp
        Polynomial.cpp
        Polynomial.h
        Term.cpp
        Term.h)
