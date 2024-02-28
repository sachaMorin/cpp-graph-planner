cmake_minimum_required(VERSION 3.27)
project(cpp-planner)

set(CMAKE_CXX_STANDARD 20)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


include_directories(include)
add_library(Graph
        src/GraphComponents.cpp
        src/DirectedGraph.cpp
        src/UndirectedGraph.cpp
        src/GridGraph.cpp)


add_executable(cpp-planner main.cpp)
target_link_libraries(cpp-planner Graph)

add_executable(build-default-map build-default-map.cpp)
target_link_libraries(build-default-map ${OpenCV_LIBS} )

add_executable(occupancy-planner occupancy-planner.cpp)
target_link_libraries(occupancy-planner Graph)
target_link_libraries(occupancy-planner ${OpenCV_LIBS} )
