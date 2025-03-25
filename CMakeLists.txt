cmake_minimum_required(VERSION 3.26)
project(Analyzer)

set(CMAKE_CXX_STANDARD 23)

add_executable(Analyzer main.cpp
        UeRrc.hpp
        UeRrc.cpp
        NetworkRrc.hpp
        NetworkRrc.cpp)
