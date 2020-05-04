cmake_minimum_required(VERSION 3.15)
project(Final)

set (input01 "")
set (input02 "")
set (input03 "")
set (input04 "")
set (output01 "")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04 output01)
    configure_file(${file} ${file} COPYONLY)
endforeach()


set(CMAKE_CXX_STANDARD 14)

add_executable(Final main.cpp edge.cpp edge.cpp node.h node.cpp AdjacencyList.h salesman.cpp salseman.h DSStack.h)