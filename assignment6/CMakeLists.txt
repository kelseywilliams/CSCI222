cmake_minimum_required(VERSION 3.27)
project(assignment6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment6
        Cipher.cpp
        Cipher.h
        main.cpp
        Playfair.cpp)
