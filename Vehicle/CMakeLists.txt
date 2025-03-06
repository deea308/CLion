cmake_minimum_required(VERSION 3.27)
project(Vehicle)

set(CMAKE_CXX_STANDARD 17)

add_executable(Vehicle main.cpp
        Vehicle.h
        Vehicle.cpp
        RentalAgency.h
        RentalAgency.cpp)
