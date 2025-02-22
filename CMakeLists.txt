cmake_minimum_required(VERSION 3.30)
project(PRISM)

set(CMAKE_CXX_STANDARD 20)

add_executable(PRISM main.cpp
        Utils.h
        Utils.cpp
        Point.h
        Point.cpp
        Prism.h
        Prism.cpp
)
