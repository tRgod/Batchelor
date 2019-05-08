cmake_minimum_required(VERSION 3.13)
project(clustering)
find_package(PCL 1.9 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})


set(CMAKE_CXX_STANDARD 14)

add_executable(clustering main.cpp)