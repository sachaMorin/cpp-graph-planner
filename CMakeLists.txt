cmake_minimum_required(VERSION 3.27)
project(cpp-planner)

set(CMAKE_CXX_STANDARD 20)


add_executable(cpp-planner main.cpp
        src/GraphComponents.cpp
        include/GraphComponents.h
        src/DirectedGraph.cpp
        include/DirectedGraph.h
        src/UndirectedGraph.cpp
        include/UndirectedGraph.h)
