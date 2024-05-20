cmake_minimum_required(VERSION 3.27)
project(assignment8)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment8
        BankAccount.cpp
        BankAccount.h
        main.cpp
        Portfolio.cpp
        ComboLock.cpp)
