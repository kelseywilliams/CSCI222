cmake_minimum_required(VERSION 3.27)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab4
        TrafficSim.cpp
        TrafficSim.h
        Place.cpp
        Road.cpp
        main.cpp
        Vehicle.cpp
        Vehicle.h
        Motorcycle.cpp
        Motorcycle.h
        VehicleQueue.cpp
        VehicleQueue.h)
