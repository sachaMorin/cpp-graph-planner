cmake_minimum_required(VERSION 3.27)
project(cpp-planner)

set(CMAKE_CXX_STANDARD 20)


add_executable(cpp-planner main.cpp
        src/Node.cpp
        include/Node.h
        src/Graph.cpp
        include/Graph.h)
